function data_snapshots ($) {

    function make_img_url(dsmn,ptk,stk) {
        if (dsmn === "ghcntempm") {
            return "http://datasnapshots-images.nemac.com:8080/ghcntemp/monthly/620/" + ptk + "/ghcntempm--620--" + ptk + "-" + stk + ".png";
        }
        return "http://datasnapshots-images.nemac.com:8080/usdm/620/" + ptk + "/usdm--620--" + ptk + "-" + stk + ".png";
    }

    function set_img(dsmn,ptk,stk) {
        $('#dss-disimg').attr('src', make_img_url(dsmn,ptk,stk));
        $('div.dss-title').text(ptk + ' / ' + stk);
    }

    $('document').ready(function() {
        var dsmn = Drupal.settings.data_snapshots.snapshots.dsmn,
            current_ptk_index = 0, // not correct, fix later!
            current_stk_index = 0; // not correct, fix later!
        var ptks = Drupal.settings.data_snapshots.snapshots.p;
        var stks = [];

        function hideStuff() {
            $('.dss-footer').animate({'opacity' : 0.0}, 200);
        }
        function showStuff() {
            $('.dss-footer').animate({'opacity' : 1.0}, 200);
        }

        $('#dss-yearslider').slider({
            'min' : 0,
            'max' : ptks.length-1,
            'value' : current_ptk_index,
            'change' : function(event, ui) {
                current_ptk_index = $(this).slider('value');
                stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
                set_img(dsmn,ptks[current_ptk_index],stks[current_stk_index]);
                config_stk_slider();
            },
            'slide' : function(event, ui) {
                current_ptk_index = $(this).slider('value');
                stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
                set_img(dsmn,ptks[current_ptk_index],stks[current_stk_index]);
            },
            'start' : function(event, ui) {
                hideStuff();
            },
            'stop' : function(event, ui) {
                showStuff();
            }
        });

        function config_stk_slider() {
            $('#dss-timeslider').slider({
                'min' : 0,
                'max' : stks.length-1,
                'value' : current_stk_index,
                'change' : function(event, ui) {
                    current_stk_index = $(this).slider('value');
                    set_img(dsmn,ptks[current_ptk_index],stks[current_stk_index]);
                },
                'slide' : function(event, ui) {
                    current_stk_index = $(this).slider('value');
                    set_img(dsmn,ptks[current_ptk_index],stks[current_stk_index]);
                },
                'start' : function(event, ui) {
                    hideStuff();
                },
                'stop' : function(event, ui) {
                    showStuff();
                }           
            });

        }

        stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
        config_stk_slider();

    });

}
