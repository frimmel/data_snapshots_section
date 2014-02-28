(function($) {

    function make_img_url(dsmn, ptk, stk) {
	var pattern = Drupal.settings.data_snapshots.patterns[dsmn];

	return pattern.replace(/\{dsmn\}/g, dsmn)
	    .replace(/\{ptk\}/g, ptk)
	    .replace(/\{stk\}/g, stk);
    }

    function set_url(dsmn, ptk, stk, theme) {
	var url;
	dsmn = dsmn.replace(/_/g, "");// URL aliases strip out underscores
	if (window.history && window.history.replaceState) {
	    url = (stk !== null) ? dsmn + "-" + ptk + "-" + stk + "?theme=" + theme : dsmn + "-" + ptk + "?theme=" + theme;
	    window.history.replaceState({}, "", url);
	}
    }

    function set_img(dsmn, ptk, stk) {
        $('.field-name-field-ds-disimg img').attr('src', make_img_url(dsmn,ptk,stk));
        $('div.dss-title').text(ptk + ' / ' + stk);

	set_url(dsmn, ptk, stk, $("#dss-theme-dropdown").val());
    }

    function set_title(html) {
	$(".field-name-title h2").text(html);
	document.title = html;
    }

    function set_annotation(html) {
	$(".group-footer").html(html);
    }

    function set_downloads(html) {
	var new_links = $(html).find("ul");
	$(".field-name-field-ds-dloads ul").replaceWith(new_links);
    }

    function set_permalink(html) {
	$(".field-name-data-snapshot-permalink .field-items .field-item").text(html);
    }

    function set_date_generated(html) {
	$(".field-name-field-ds-dtgen").replaceWith(html);
    }

    function set_primary_tabs(nid) {
	var re = /(\/node\/)(\d+)(\/\w+)/,
	    pattern = "$1" + nid + "$3",
	    $links = $(".tabs .primary a"),
	    $link,
	    href,
	    i;

	for (i = 0; i < $links.length; i++) {
	    $link = $($links[i]);
	    href = $link.attr("href").replace(re, pattern);
	    $link.attr("href", href);
	}
    }

    function set_slider_names(type) {
	var labels = {
	    Annual : {
		ptk : "Year:",
		stk : ""
	    },
	    Monthly : {
		ptk : "Year:",
		stk : "Month:"
	    },
	    Weekly : {
		ptk : "Year:",
		stk : "Day:"
	    },
	    Custom : {
		ptk : "Date:",
		stk : ""
	    },
	};

	$(".dss-interactive-ptk-label").text(labels[type].ptk);
	$(".dss-interactive-stk-label").text(labels[type].stk);
    }

    function set_slider_labels(type, start, end, freq) {
	var startlabel, endlabel;
	if (type === "ptk") {
	    startlabel = $("#dss-interactive-slider-ptk-start-label");
	    endlabel = $("#dss-interactive-slider-ptk-end-label");
	} else if (type === "stk") {
	    startlabel = $("#dss-interactive-slider-stk-start-label");
	    endlabel = $("#dss-interactive-slider-stk-end-label");
	}

	if (type === "stk" && freq === "Annual") {
	    start = "";
	    end = "";
	}

	startlabel.text(start);
	endlabel.text(end);
    }

    function set_slider_popups(selector, value, slider, steps, position) {
	var afterElemBorder = 6,// need to add to margin for correct placement. Change if css changes.
	    $elem = $(selector),
	    elemPosition = (position * ($(slider).width() / (steps - 1))) + "px",
	    elemWidth, marginLeft;

	$elem.text(value);

	elemWidth = $elem.width() / 2;
	marginLeft = (-elemWidth + afterElemBorder) + "px";

	$elem.css("margin-left", marginLeft)
	    .css("left", elemPosition);
    }

    function set_ptk_slider_popup(selector, ptk, stk, frequency, slider, steps, position) {
	var popupText = ptk;

	if (frequency !== "Annual") {
	    popupText += "-" + stk;
	}

	set_slider_popups(selector, popupText, slider, steps, position);
    }

    function init_dropdowns() {
	var data_snapshots = Drupal.settings.data_snapshots,
	    dsmn = data_snapshots.snapshots.dsmn,
	    themes = data_snapshots.themes,
	    data_sources = data_snapshots.datasources,
	    $theme_dropdown = $("#dss-theme-dropdown"),
	    $data_source_dropdown = $("#dss-data-source-dropdown"),
	    init_theme = data_snapshots.init_theme,
	    foundTheme = false,
	    theme, i;

	if (init_theme && themes.indexOf(init_theme) !== -1 && data_sources[init_theme].length > 0) {
	    for (i = 0; i < data_sources[init_theme].length; i++) {
		if (data_sources[init_theme][i].mname === dsmn) {
		    foundTheme = true;
		}
	    }
	}

	for (i = 0; i < themes.length; i++) {
	    theme = themes[i];
	    if (data_sources[theme].length === 0) {
		continue;
	    }
	    $theme_dropdown.append($("<option>", { value: theme })
				   .text(theme));

	    // TODO: Add polyfill of indexOf
	    if (!foundTheme) {
		var j;

		for (j = 0; j < data_sources[theme].length; j++) {
		    if (data_sources[theme][j].mname === dsmn) {
			init_theme = theme;
			foundTheme = true;
		    }
		}
	    }
	}


	for (i = 0; i < data_sources[init_theme].length; i++) {
	    $data_source_dropdown.append($("<option>", { value: data_sources[init_theme][i].mname })
					 .text(data_sources[init_theme][i].oname));
	}

	$theme_dropdown.val(init_theme);
	$data_source_dropdown.val(dsmn);
    }

    function format_evergreen_answer(answer) {
	var answer_length = 250,
	    answer_length_ellipsis = answer_length + 3;

	// strip all tags
	answer = $("<div/>").html(answer).text();

	if (answer.length > answer_length_ellipsis) {
	    answer = answer.substring(0, answer_length).trim() + "...";
        }

	return answer;
    }

    function switch_data_source_content(node) {
	var framing_answer = format_evergreen_answer(node.field_dssds_framing_q_answer.und[0].safe_value),
	    secondary_answer = format_evergreen_answer(node.field_dssds_secondary_q_answ.und[0].safe_value),
	    $evergreen_wrapper = $(".field-name-field-ds-dsds-evergreen"),
	    $framing_question = $evergreen_wrapper.find(".field_dssds_framing_question"),
	    $framing_answer = $evergreen_wrapper.find(".field_dssds_framing_q_answer p"),
	    $secondary_question = $evergreen_wrapper.find(".field_dssds_secondary_questi"),
	    $secondary_answer = $evergreen_wrapper.find(".field_dssds_secondary_q_answ p"),
	    $read_more_link = $evergreen_wrapper.find(".dss-question-read-more a");

	$framing_question.text(node.field_dssds_framing_question.und[0].value);
	$framing_answer.text(framing_answer);
	$secondary_question.text(node.field_dssds_secondary_questi.und[0].value);
	$secondary_answer.text(secondary_answer);
	$read_more_link.attr("href", "/node/" + node.nid);
    };

    var xhr;

    function switchDataSnapshotContentSuccessHandler(result) {
	set_title(result.title_html);
	set_annotation(result.body_html);
	set_downloads(result.download_html);
	set_permalink(result.permalink_html);
	set_date_generated(result.date_html);
	set_primary_tabs(result.nid);
	xhr = null;
    }

    function switchDataSnapshotContent(dsmn, ptk, stk) {
	var parameters = {
	    "type" : "data_snapshot",
	    "dsmn" : dsmn,
	    "ptk"  : ptk
	};
	if (stk !== null) {
	    parameters.stk = stk
	}

	if (xhr) {
	    xhr.abort();
	}

	xhr = $.ajax({
	    type    : "POST",
	    url     : "/data-snapshots/ajax",
	    data    : parameters,
	    success : switchDataSnapshotContentSuccessHandler
	});
    }

    $('document').ready(function() {
	var data_snapshots_options = Drupal.settings.data_snapshots,
	    snapshots = data_snapshots_options.snapshots,
            dsmn = snapshots.dsmn,
	    init_ptk = snapshots.init_ptk,
	    ptks = snapshots.p,
            current_ptk_index = ptks.indexOf(init_ptk),
	    stks = snapshots.s[ptks[current_ptk_index]],
            current_stk_index = snapshots.s[init_ptk].indexOf(snapshots.init_stk);

        config_ptk_slider();
        config_stk_slider();

	init_dropdowns();
	data_source_stk_change();
	$('#dss-data-source-dropdown').change(data_source_dropdown_change);
	$('#dss-theme-dropdown').change(theme_dropdown_change);
	set_slider_names(data_snapshots_options.frequencies[dsmn]);

        function hideStuff() {
            $('.group-footer').html("").stop(true, true).animate({'opacity' : 0.0}, 200).html("");
        }

        function showStuff() {
	    $('.group-footer').stop(true, true).animate({'opacity' : 1.0}, 200);
        }

	function config_ptk_slider() {
	    var ptk_popup_selector = "#dss-interactive-slider-ptk-popup";

            $('#dss-yearslider').slider({
                'min' : 0,
                'max' : ptks.length - 1,
                'value' : current_ptk_index,
                'change' : function(event, ui) {
                    current_ptk_index = ui.value;
                    stks = Drupal.settings.data_snapshots.snapshots.s[ptks[current_ptk_index]];
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                    config_stk_slider();
                },
                'slide' : function(event, ui) {
		    var data_snapshots_properties = Drupal.settings.data_snapshots,
			frequency = data_snapshots_properties.frequencies[dsmn],
			ptk, stk, lastStk,
			popupText;

                    current_ptk_index = ui.value;

		    ptk = ptks[current_ptk_index];
                    stks = data_snapshots_properties.snapshots.s[ptk];
		    lastStk = stks[stks.length - 1];

		    if (current_stk_index >= stks.length) {
			stk = lastStk;
		    } else {
			stk = stks[current_stk_index];
		    }

		    set_img(dsmn, ptk, stk);
		    set_slider_labels("stk", stks[0], lastStk, frequency);
		    set_ptk_slider_popup(ptk_popup_selector, ptk, stk, frequency, this, ptks.length, current_ptk_index);
                },
                'start' : function(event, ui) {
		    set_ptk_slider_popup(ptk_popup_selector, ptks[current_ptk_index], stks[current_stk_index], Drupal.settings.data_snapshots.frequencies[dsmn], this, ptks.length, ui.value);
		    $(ptk_popup_selector).addClass("dss-interactive-slider-popup-active");
                    hideStuff();
                },
                'stop' : function(event, ui) {
		    $(ptk_popup_selector).removeClass("dss-interactive-slider-popup-active");
		    switchDataSnapshotContent(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                    showStuff();
                }
            });
	    set_slider_labels("ptk", ptks[0], ptks[ptks.length - 1], Drupal.settings.data_snapshots.frequencies[dsmn]);
	};

        function config_stk_slider() {
	    var stk_popup_selector = "#dss-interactive-slider-stk-popup";

            $('#dss-timeslider').slider({
                'min' : 0,
                'max' : stks.length - 1,
                'value' : current_stk_index,
                'change' : function(event, ui) {
                    current_stk_index = ui.value;
                    set_img(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                },
                'slide' : function(event, ui) {
		    var ptk, stk;
		    current_stk_index = ui.value;

		    ptk = ptks[current_ptk_index];
		    stk = stks[current_stk_index];

		    set_img(dsmn, ptk, stk);
		    set_slider_popups(stk_popup_selector, ptk + "-" + stk, this, stks.length, current_stk_index);
                },
                'start' : function(event, ui) {
		    set_slider_popups(stk_popup_selector, ptks[current_ptk_index] + "-" + stks[current_stk_index], this, stks.length, ui.value);
		    $(stk_popup_selector).addClass("dss-interactive-slider-popup-active");
                    hideStuff();
                },
                'stop' : function(event, ui) {
		    $(stk_popup_selector).removeClass("dss-interactive-slider-popup-active");
		    switchDataSnapshotContent(dsmn, ptks[current_ptk_index], stks[current_stk_index]);
                    showStuff();
                }           
            });

	    set_slider_labels("stk", stks[0], stks[stks.length - 1], Drupal.settings.data_snapshots.frequencies[dsmn]);
        }

	function data_source_stk_change() {
	    var frequencies = Drupal.settings.data_snapshots.frequencies,
		disabledStk = ["Annual"],
		$dsstimeslider = $('#dss-timeslider'),
		val;

	    if (disabledStk.indexOf(frequencies[dsmn]) !== -1) {
		val = true;
	    } else {
		val = false;
	    }
	    $dsstimeslider.slider("option", "disabled", val);
	}

	function theme_dropdown_change() {
	    var new_theme = $(this).val(),
		data_sources = Drupal.settings.data_snapshots.datasources[new_theme],
		$data_source_dropdown = $('#dss-data-source-dropdown'),
		data_source, mname,
		change_data_source = true,
		i;

	    $data_source_dropdown.empty();

	    for (i = 0; i < data_sources.length; i++) {
		data_source = data_sources[i];
		mname = data_source.mname;
		$data_source_dropdown.append($("<option>", { value: mname })
					     .text(data_source.oname));
		if (dsmn === mname) {
		    $data_source_dropdown.val(mname);
		    change_data_source = false;
		}
	    }

	    if (change_data_source === true) {
		set_data_source(data_sources[0].mname);
	    }

	    set_url(dsmn, ptks[current_ptk_index], stks[current_stk_index], new_theme);
	}

	function data_source_dropdown_change() {
	    set_data_source($(this).val());
	}

	function set_data_source_success_handler(msg) {
	    var result = msg.callback,
		dates = result.dates,
		new_dsmn = msg.request.new_dsmn,
		ptk, stk;

	    dates.dsmn = new_dsmn;
	    Drupal.settings.data_snapshots.snapshots = dates;

	    current_ptk_index = dates.p.indexOf(result.ptk);
	    current_stk_index = dates.s[result.ptk].indexOf(result.stk);
	    ptks = dates.p;
	    ptk = ptks[current_ptk_index];
	    stks = dates.s[ptk];
	    stk = stks[current_stk_index];

	    dsmn = new_dsmn;

	    set_img(dsmn, ptk, stk);
	    config_ptk_slider();
	    config_stk_slider();

	    switch_data_source_content(msg.node);
	    switchDataSnapshotContent(dsmn, ptk, stk);
	    data_source_stk_change();
	    set_slider_names(Drupal.settings.data_snapshots.frequencies[dsmn]);
	}

	function set_data_source(new_dsmn) {
	    var frequencies = Drupal.settings.data_snapshots.frequencies;

	    $.ajax({
		type    : "POST",
	        url     : "/data-snapshots/ajax",
		success : set_data_source_success_handler,
		data    : {
			    "type"              : "data_source",
			    "current_dsmn"      : dsmn,
			    "new_dsmn"          : new_dsmn,
			    "current_frequency" : frequencies[dsmn],
			    "new_frequency"     : frequencies[new_dsmn],
			    "ptk"               : ptks[current_ptk_index],
			    "stk"               : stks[current_stk_index]
		          }
	    });
	}
    });

})(jQuery);
