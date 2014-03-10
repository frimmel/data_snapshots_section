/* Data Snapshots
 * Copyright 2014 University of North Carolina at Asheville
 * Released under the MIT license
 */
(function($) {

    if (!Array.prototype.indexOf) {
        Array.prototype.indexOf = function (searchElement, fromIndex) {
            if ( this === undefined || this === null ) {
                throw new TypeError( '"this" is null or not defined' );
            }

            var length = this.length >>> 0; // Hack to convert object.length to a UInt32

            fromIndex = +fromIndex || 0;

            if (Math.abs(fromIndex) === Infinity) {
                fromIndex = 0;
            }

            if (fromIndex < 0) {
                fromIndex += length;
                if (fromIndex < 0) {
                    fromIndex = 0;
                }
            }

            for (;fromIndex < length; fromIndex++) {
                if (this[fromIndex] === searchElement) {
                    return fromIndex;
                }
            }

            return -1;
        };
    }

    if (!String.prototype.trim) {
        String.prototype.trim = function () {
            return this.replace(/^\s+|\s+$/g, '');
        };
    }

    function getPropertiesObject() {
        return Drupal.settings.data_snapshots;
    }

    function getDsmn() {
        return getPropertiesObject().snapshots.dsmn;
    }

    function getPattern(dsmn) {
        return getPropertiesObject().patterns[dsmn];
    }

    function getFrequency(dsmn) {
        return getPropertiesObject().frequencies[dsmn]
    }

    function getPtks() {
        return getPropertiesObject().snapshots.p;
    }

    function getStks(ptk) {
        if (determineStkDisabled() === true) {
            return [];
        } else {
            return getPropertiesObject().snapshots.s[ptk];
        }
    }

    function makeImgUrl(dsmn, ptk, stk) {
        var pattern = getPattern(dsmn);

        return pattern.replace(/\{dsmn\}/g, dsmn)
            .replace(/\{ptk\}/g, ptk)
            .replace(/\{stk\}/g, stk);
    }

    function setUrl(dsmn, ptk, stk, theme) {
        var url;
        dsmn = dsmn.replace(/_/g, "");// URL aliases strip out underscores
        if (window.history && window.history.replaceState) {
            url = (determineStkDisabled() === false) ? dsmn + "-" + ptk + "-" + stk + "?theme=" + theme : dsmn + "-" + ptk + "?theme=" + theme;
            window.history.replaceState({}, "", url);
        }
    }

    function setImg(dsmn, ptk, stk) {
        $('.field-name-field-ds-disimg img').attr('src', makeImgUrl(dsmn, ptk, stk));

        setUrl(dsmn, ptk, stk, $("#dss-theme-dropdown").val());
    }

    function setTitle(html) {
        $(".field-name-title h2").text(html);
        document.title = html;
    }

    function setAnnotation(html) {
        $(".group-footer").html(html);
    }

    function setDownloads(html) {
        var newLinks = $(html).find("ul");
        $(".field-name-field-ds-dloads ul").replaceWith(newLinks);
    }

    function setPermalink(html) {
        $(".field-name-data-snapshot-permalink .field-label").permalink('url', html);
    }

    function setDateGenerated(html) {
        $(".field-name-field-ds-dtgen").replaceWith(html);
    }

    function setPrimaryTabs(nid) {
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

    function setSliderNames(type) {
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

    function setSliderLabels(type, start, end, freq) {
        var $startLabel, $endLabel;
        if (type === "ptk") {
            $startLabel = $("#dss-interactive-slider-ptk-start-label");
            $endLabel = $("#dss-interactive-slider-ptk-end-label");
        } else if (type === "stk") {
            $startLabel = $("#dss-interactive-slider-stk-start-label");
            $endLabel = $("#dss-interactive-slider-stk-end-label");
        }

        if (type === "stk" && determineStkDisabled() === true) {
            start = "";
            end = "";
        }

        $startLabel.text(start);
        $endLabel.text(end);
    }

    function setSliderPopups(selector, value, slider, steps, position) {
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

    function setPtkSliderPopup(selector, ptk, stk, frequency, slider, steps, position) {
        var popupText = ptk;

        if (determineStkDisabled() === false) {
            popupText += "-" + stk;
        }

        setSliderPopups(selector, popupText, slider, steps, position);
    }

    function initDropdowns() {
        var dataSnapshots = getPropertiesObject(),
            dsmn = getDsmn(),
            themes = dataSnapshots.themes,
            dataSources = dataSnapshots.data_sources,
            $themeDropdown = $("#dss-theme-dropdown"),
            $dataSourceDropdown = $("#dss-data-source-dropdown"),
            initTheme = dataSnapshots.init_theme,
            foundTheme = false,
            theme, i;

        if (initTheme && themes.indexOf(initTheme) !== -1 && dataSources[initTheme].length > 0) {
            for (i = 0; i < dataSources[initTheme].length; i++) {
                if (dataSources[initTheme][i].mname === dsmn) {
                    foundTheme = true;
                }
            }
        }

        for (i = 0; i < themes.length; i++) {
            theme = themes[i];
            if (dataSources[theme].length === 0) {
                continue;
            }
            $themeDropdown.append($("<option>", { value: theme })
                                   .text(theme));

            if (!foundTheme) {
                var j;

                for (j = 0; j < dataSources[theme].length; j++) {
                    if (dataSources[theme][j].mname === dsmn) {
                        initTheme = theme;
                        foundTheme = true;
                    }
                }
            }
        }


        for (i = 0; i < dataSources[initTheme].length; i++) {
            $dataSourceDropdown.append($("<option>", { value: dataSources[initTheme][i].mname })
                                         .text(dataSources[initTheme][i].oname));
        }

        $themeDropdown.val(initTheme);
        $dataSourceDropdown.val(dsmn);
    }

    function determineStkDisabled() {
        if (getPropertiesObject().snapshots.s.length === 0) {
            return true;
        } else {
            return false;
        }
    }

    function formatEvergreenText(text) {
        var textLength = 500,
            textLengthEllipsis = textLength + 3;

        // strip all tags
        text = $("<div/>").html(text).text();

        if (text.length > textLengthEllipsis) {
            text = text.substring(0, textLength).trim() + "...";
        }

        return text;
    }

    function switchDataSourceContent(node) {
        var framingQuestion = formatEvergreenText(node.field_dssds_framing_question.und[0].safe_value),
            framingAnswer = formatEvergreenText(node.field_dssds_framing_q_answer.und[0].value),
            secondaryQuestion = formatEvergreenText(node.field_dssds_secondary_questi.und[0].value),
            secondaryAnswer = formatEvergreenText(node.field_dssds_secondary_q_answ.und[0].safe_value),
            $evergreenWrapper = $(".field-name-field-ds-dsds-evergreen"),
            $framingQuestion = $evergreenWrapper.find(".field_dssds_framing_question"),
            $framingAnswer = $evergreenWrapper.find(".field_dssds_framing_q_answer p"),
            $secondaryQuestion = $evergreenWrapper.find(".field_dssds_secondary_questi"),
            $secondaryAnswer = $evergreenWrapper.find(".field_dssds_secondary_q_answ p"),
            $readMoreLink = $evergreenWrapper.find(".dss-question-read-more a");

        $framingQuestion.text(framingQuestion);
        $framingAnswer.text(framingAnswer);
        $secondaryQuestion.text(secondaryQuestion);
        $secondaryAnswer.text(secondaryAnswer);
        $readMoreLink.attr("href", "/node/" + node.nid);
    };

    var xhr;

    function switchDataSnapshotContentSuccessHandler(result) {
        setTitle(result.title_html);
        setAnnotation(result.body_html);
        setDownloads(result.download_html);
        setPermalink(result.permalink_html);
        setDateGenerated(result.date_html);
        setPrimaryTabs(result.nid);
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

    function dismissPermalink() {
        $(".field-name-data-snapshot-permalink .closebutton").click();
    }

    $('document').ready(function() {
        var snapshots = getPropertiesObject().snapshots,
            dsmn = getDsmn(),
            ptks = getPtks(),
            stks = getStks(snapshots.init_ptk),
            currentPtkIndex = ptks.indexOf(snapshots.init_ptk),
            currentStkIndex = stks.indexOf(snapshots.init_stk),
            currentPermalink = $(".field-name-data-snapshot-permalink .field-items .field-item").text();

        // clear out the permalink field value
        $(".field-name-data-snapshot-permalink .field-items .field-item").text("");
        // change the "Permalink:" label to just "Permalink" (without the colon)
        $(".field-name-data-snapshot-permalink .field-label").text("Permalink");

        // initialize the permalink widget
        $(".field-name-data-snapshot-permalink .field-label").permalink({
            url : currentPermalink
        });

        configPtkSlider();
        configStkSlider();

        initDropdowns();
        dataSourceStkChange();
        $('#dss-data-source-dropdown').change(dataSourceDropdownChange);
        $('#dss-theme-dropdown').change(themeDropdownChange);
        setSliderNames(getFrequency(dsmn));

        function hideElements() {
            $('.group-footer').html("").stop(true, true).animate({'opacity' : 0.0}, 200).html("");
        }

        function showElements() {
            $('.group-footer').stop(true, true).animate({'opacity' : 1.0}, 200);
        }

        function configPtkSlider() {
            var ptkPopupSelector = "#dss-interactive-slider-ptk-popup";

            $('#dss-interactive-slider-ptk-slider').slider({
                'min' : 0,
                'max' : ptks.length - 1,
                'value' : currentPtkIndex,
                'change' : function(event, ui) {
                    currentPtkIndex = ui.value;
                    stks = getStks(ptks[currentPtkIndex]);
                    setImg(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
                    configStkSlider();
                },
                'slide' : function(event, ui) {
                    var frequency = getFrequency(dsmn),
                        ptk, stk, lastStk,
                        popupText;

                    currentPtkIndex = ui.value;

                    ptk = ptks[currentPtkIndex];
                    stks = getStks(ptk);
                    lastStk = stks[stks.length - 1];

                    if (currentStkIndex >= stks.length) {
                        stk = lastStk;
                    } else {
                        stk = stks[currentStkIndex];
                    }

                    setImg(dsmn, ptk, stk);
                    setSliderLabels("stk", stks[0], lastStk, frequency);
                    setPtkSliderPopup(ptkPopupSelector, ptk, stk, frequency, this, ptks.length, currentPtkIndex);
                },
                'start' : function(event, ui) {
                    dismissPermalink();
                    setPtkSliderPopup(ptkPopupSelector, ptks[currentPtkIndex], stks[currentStkIndex], getFrequency[dsmn], this, ptks.length, ui.value);
                    $(ptkPopupSelector).addClass("dss-interactive-slider-popup-active");
                    hideElements();
                },
                'stop' : function(event, ui) {
                    $(ptkPopupSelector).removeClass("dss-interactive-slider-popup-active");
                    if (determineStkDisabled === false) {
                        switchDataSnapshotContent(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
                    } else {
                        switchDataSnapshotContent(dsmn, ptks[currentPtkIndex]);
                    }
                    showElements();
                }
            });
            setSliderLabels("ptk", ptks[0], ptks[ptks.length - 1], getFrequency[dsmn]);
        };

        function configStkSlider() {
            var stkPopupSelector = "#dss-interactive-slider-stk-popup";

            $('#dss-interactive-slider-stk-slider').slider({
                'min' : 0,
                'max' : stks.length - 1,
                'value' : currentStkIndex,
                'change' : function(event, ui) {
                    currentStkIndex = ui.value;
                    setImg(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
                },
                'slide' : function(event, ui) {
                    var ptk, stk;
                    currentStkIndex = ui.value;

                    ptk = ptks[currentPtkIndex];
                    stk = stks[currentStkIndex];

                    setImg(dsmn, ptk, stk);
                    setSliderPopups(stkPopupSelector, ptk + "-" + stk, this, stks.length, currentStkIndex);
                },
                'start' : function(event, ui) {
                    dismissPermalink();
                    setSliderPopups(stkPopupSelector, ptks[currentPtkIndex] + "-" + stks[currentStkIndex], this, stks.length, ui.value);
                    $(stkPopupSelector).addClass("dss-interactive-slider-popup-active");
                    hideElements();
                },
                'stop' : function(event, ui) {
                    $(stkPopupSelector).removeClass("dss-interactive-slider-popup-active");
                    switchDataSnapshotContent(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
                    showElements();
                }           
            });

            setSliderLabels("stk", stks[0], stks[stks.length - 1], getFrequency(dsmn));
        }

        function dataSourceStkChange() {
            $('#dss-interactive-slider-stk-slider').slider("option", "disabled", determineStkDisabled());
        }

        function themeDropdownChange() {
            var newTheme = $(this).val(),
                dataSources = getPropertiesObject().data_sources[newTheme],
                $dataSourceDropdown = $('#dss-data-source-dropdown'),
                dataSource, mname,
                changeDataSource = true,
                i;

            $dataSourceDropdown.empty();

            for (i = 0; i < dataSources.length; i++) {
                dataSource = dataSources[i];
                mname = dataSource.mname;
                $dataSourceDropdown.append($("<option>", { value: mname })
                                             .text(dataSource.oname));
                if (dsmn === mname) {
                    $dataSourceDropdown.val(mname);
                    changeDataSource = false;
                }
            }

            if (changeDataSource === true) {
                setDataSource(dataSources[0].mname);
            }

            setUrl(dsmn, ptks[currentPtkIndex], stks[currentStkIndex], newTheme);
            dismissPermalink();
        }

        function dataSourceDropdownChange() {
            setDataSource($(this).val());
            dismissPermalink();
        }

        function setDataSourceSuccessHandler(result) {
            var dates = result.dates,
                ptk, stk;

            getPropertiesObject().snapshots = dates;

            dsmn = getDsmn();
            ptks = getPtks();
            stks = getStks(result.ptk);
            currentPtkIndex = ptks.indexOf(result.ptk);
            ptk = ptks[currentPtkIndex];
            if (determineStkDisabled() === true) {
                currentStkIndex = 0;
            } else {
                currentStkIndex = stks.indexOf(result.stk);
                stk = stks[currentStkIndex];
            }

            setImg(dsmn, ptk, stk);
            configPtkSlider();
            configStkSlider();

            switchDataSourceContent(result.node);
            switchDataSnapshotContent(dsmn, ptk, stk);
            dataSourceStkChange();
            setSliderNames(getFrequency(dsmn));
        }

        function setDataSource(newDsmn) {
            $.ajax({
                type    : "POST",
                url     : "/data-snapshots/ajax",
                success : setDataSourceSuccessHandler,
                data    : {
                            "type"              : "data_source",
                            "current_dsmn"      : dsmn,
                            "new_dsmn"          : newDsmn,
                            "current_frequency" : getFrequency(dsmn),
                            "new_frequency"     : getFrequency(newDsmn),
                            "ptk"               : ptks[currentPtkIndex],
                            "stk"               : stks[currentStkIndex]
                          }
            });
        }
    });

})(jQuery);
