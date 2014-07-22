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

    function getAllStks() {
        return getPropertiesObject().snapshots.s;
    }

    function getStks(ptk) {
        if (determineStkDisabled() === true) {
            return [];
        } else {
            return getAllStks()[ptk];
        }
    }

    function makeImgUrl(dsmn, ptk, stk) {
        var pattern = getPattern(dsmn);

        return pattern.replace(/\{dsmn\}/g, dsmn)
            .replace(/\{ptk\}/g, ptk)
            .replace(/\{stk\}/g, stk);
    }

    function setUrl(dsmn, ptk, stk, theme) {
        console.log("DOG");
        var url;
        dsmn = dsmn.replace(/_/g, "");// URL aliases strip out underscores
        if (window.history && window.history.replaceState) {
            url = (determineStkDisabled() === false) ? dsmn + "-" + ptk + "-" + stk + "?theme=" + theme : dsmn + "-" + ptk + "?theme=" + theme;
            window.history.replaceState({}, "", url);
        }
    }

    function setImg(dsmn, ptk, stk) {
        $('.field-name-field-ds-disimg img').attr('src', makeImgUrl(dsmn, ptk, stk));

        setUrl(dsmn, ptk, stk, $(".dss-accordion .ui-accordion-header-active").attr("value"));
    }

    function setTitle(html) {
        $(".field-name-title h2").text(html);
        document.title = html;
    }

    function showAnnotation() {
        $(".field-name-body").addClass("expanded");
        $(".annotation-toggle").text("read less -");
        showAnnotationLabels();
    }

    function showAnnotationLabels() {
        if ($(".field-name-body .field-items").text().trim() !== "") {
            $(".field-name-body .field-label").removeClass("hidden");
            $(".field-name-body .annotation-toggle-wrapper").removeClass("hidden");
        }
    }

    function hideAnnotation() {
        $(".field-name-body").removeClass("expanded");
        $(".annotation-toggle").text("read more +");
        hideAnnotationLabels();
    }

    function hideAnnotationLabels() {
        if ($(".field-name-body .field-items").text().trim() === "") {
            $(".field-name-body .field-label").addClass("hidden");
            $(".field-name-body .annotation-toggle-wrapper").addClass("hidden");
        }
    }

    function setAnnotation(html) {
        console.log("HEY")
        console.log(html);
        $(".field-name-body .field-items").html(html ? $(html).children(".field-items").html() : "");
        html ? showAnnotationLabels() : hideAnnotationLabels();
        //        $(".group-footer").html(html);
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

    function setSliderPopups(selector, value, slider, steps, position) {
        var afterElemBorder = 6,// need to add to margin for correct placement. Change if css changes.
            $elem = $(selector),
            elemPosition = (75 + position * ($(slider).width() / (steps - 1))) + "px",
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

    function determineSliderOffset(index, length) {
        length--;
        return (length === 0) ? 0 : (index / length) * 100;
    };

    function replaceSliderTickmarks(wrapper, length) {
        var tickmarks = "",
            left, i;

        for (i = 0; i < length; i++) {
            left = determineSliderOffset(i, length);
            tickmarks += "<span style=\"left:" + left + "%;\"></span>";
        }

        wrapper.html(tickmarks);
    }

    function initDropdowns() {
        var dataSnapshots = getPropertiesObject(),
            dsmn = getDsmn(),
            themes = dataSnapshots.themes,
            dataSources = dataSnapshots.data_sources,
            $accordion = $("<div></div>"),
            $datasourceWrapper,
            initTheme = dataSnapshots.init_theme,
            foundTheme = false,
	    themeIndex = 0,
            theme, i, j;

        for (i = 0; i < themes.length; i++) {
            theme = themes[i];
            if (dataSources[theme].length === 0) {
                continue;
            }
            $accordion.append($("<h3/>", { value: theme }).text(theme));

            $datasourceWrapper = $("<div></div>");
            for (j = 0; j < dataSources[theme].length; j++) {
                $datasourceWrapper.append($("<div/>", { value: dataSources[theme][j].mname })
                                  .addClass("dss-data-source-dropdown " + dataSources[theme][j].scope)
                                  .text(dataSources[theme][j].oname));

                if (!foundTheme) {
                    if (dataSources[theme][j].mname === dsmn) {
                        foundTheme = true;
                    }
                }
            }
            $accordion.append($datasourceWrapper);

	    if (!foundTheme) {
		themeIndex++;
	    }
        }

        $accordion.accordion({heightStyle : "content" });
        $(".dss-accordion").append($accordion);
	if (foundTheme) {
	    $accordion.accordion("option", "active", themeIndex);
	}

        //        $themeDropdown.val(initTheme);
        //        $dataSourceDropdown.val(dsmn);
    }

    function determineStkDisabled() {
        return jQuery.isEmptyObject(getAllStks());
    }

    function formatEvergreenText(text) {
        var textLength = 450,
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
        hideAnnotation();

	$(".dss-downloads-options label").each(function (index) {
	    $(this).jqxRadioButton({
		"theme" : "ui-darkness"
	    }).bind("change", function () {
		$("#" + $(this).attr("for")).attr("checked", "checked").change();
	    });

	    console.log(index === 0)

	    if (index === 0) {
		$(this).jqxRadioButton({
		    "checked": true
		}).change();
	    }
	});

	$(".dss-downloads-ok-button").jqxButton({theme: "ui-darkness", width: 68})
	    .click(function () {
		$(".dss-downloads-popup").fadeOut(200);
	    });

	$(".dss-downloads-cancel-button").jqxButton({theme: "ui-darkness", width: 68})
	    .click(function (event) {
		event.preventDefault();
		$(".dss-downloads-popup").fadeOut(200);
	    });

	$(".dss-downloads-popup input").change(function () {
	    $("#exampleform").attr("action", $(this).attr("value"));
	});

	$(".dss-downloads-toggle").jqxToggleButton({ theme: "ui-darkness", width: '86', toggled: false })
	    .click(function () {
		$(".dss-downloads-popup").fadeToggle(200);
		$($(".dss-downloads-options label")[0]).jqxRadioButton({
		    "checked": true
		}).change();
	    });

        $("#dss-tabs-maps").click(function () {
	    $(this).addClass("active");
            $(".dss-selector-wrapper").show();
            $(".dss-text-wrapper").hide();
            $("#dss-tabs-description").removeClass("active");
        });

        $("#dss-tabs-description").click(function () {
	    $(this).addClass("active");
            $(".dss-selector-wrapper").hide();
            $(".dss-text-wrapper").show();
            $("#dss-tabs-maps").removeClass("active");
            hideAnnotation();
        });

        $(".annotation-toggle").click(function () {
            if ($(".field-name-body").hasClass("expanded")) {
                hideAnnotation();
            } else {
                showAnnotation();
            }
        });

        $(".dss-short-summary-text").text($(".field_dssds_framing_q_answer").text().split(".")[0] + ".");

	var stkPopupSelector = "#dss-interactive-slider-stk-popup";
	var ptkPopupSelector = "#dss-interactive-slider-ptk-popup";

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
        bindPtkEvents();
        bindStkEvents();

        initDropdowns();
        dataSourceStkChange();
        $(".dss-data-source-dropdown").click(dataSourceDropdownChange);
        $('#dss-theme-dropdown').change(themeDropdownChange);
        setSliderNames(getFrequency(dsmn));

	$("div[value=" + dsmn + "]").addClass("active");

        function hideElements() {
            //            $('.group-footer').html("").stop(true, true).animate({'opacity' : 0.0}, 200).html("");
        }

        function showElements() {
            //            $('.group-footer').stop(true, true).animate({'opacity' : 1.0}, 200);
        }

        function replaceTickmarks() {
            var ptkLength = ptks.length,
                stkLength = stks.length,
                $ptkTickmarks = $("#dss-interactive-slider-tickmarks-ptk"),
                $stkTickmarks = $("#dss-interactive-slider-tickmarks-stk");

            if ($ptkTickmarks.children().length !== ptkLength) {
                replaceSliderTickmarks($ptkTickmarks, ptkLength);
            }
            if ($stkTickmarks.children().length !== stkLength) {
                replaceSliderTickmarks($stkTickmarks, stkLength);
            }
        }

        function getStkMin() {
            var allStks = getAllStks(),
                ptk = ptks[0],
                stks = allStks[ptk],
                min,
                i, j;

            min = stks[0];
            if (!min) {
                for (i = 1; i < stks.length; i++) {
                    min = stks[i];
                    if (min) {
                        break;
                    }
                }
            }

            for (i = 1; i < ptks.length; i++) {
                ptk = ptks[i];
                stks = allStks[ptk];
                for (j = 0; j < stks.length; j++) {
                    if (!stks[j]) {
                        continue;
                    }
                    if (stks[j] < min) {
                        min = stks[j];
                    }
                    break;
                }
            }

            return min;
        }

        function getStkMax() {
            var allStks = getAllStks(),
                ptk = ptks[0],
                stks = allStks[ptk],
                max,
                i, j;

            max = stks[stks.length - 1];
            if (!max) {
                for (i = stks.length - 2; i >= 0; i--) {
                    max = stks[i];
                    if (max) {
                        break;
                    }
                }
            }

            for (i = 1; i < ptks.length; i++) {
                ptk = ptks[i];
                stks = allStks[ptk];
                for (j = stks.length - 1; j >= 0; j--) {
                    if (!stks[j]) {
                        continue;
                    }
                    if (stks[j] > max) {
                        max = stks[j];
                    }
                    break;
                }
            }

            return max;
        }

        function setSliderNames(type) {
            var labels = {
                    Annual : {
                        ptk : "Year:",
                        stk : "",
                        stkStart : "",
                        stkEnd : ""
                    },
                    Monthly : {
                        ptk : "Year:",
                        stk : "Month:",
                        stkStart : "Jan",
                        stkEnd : "Dec"
                    },
                    Weekly : {
                        ptk : "Year:",
                        stk : "Day:",
                        stkStart : "Jan",
                        stkEnd : "Dec"
                    },
                    Custom : {
                        ptk : "",
                        stk : "Date:",
                        stkStart : getStkMin,
                        stkEnd : getStkMax
                    },
                },
                label = labels[type],
                stkStart = label.stkStart,
                stkEnd = label.stkEnd;

            $(".field-name-field-ds-ptk > .field-label").text(label.ptk);
            $(".field-name-field-ds-stk > .field-label").text(label.stk);
            $("#dss-interactive-slider-stk-start-label").text((typeof(stkStart) === "string") ? stkStart : stkStart());
            $("#dss-interactive-slider-stk-end-label").text((typeof(stkEnd) === "string") ? stkEnd : stkEnd());
            $("#dss-interactive-slider-ptk-start-label").text(ptks[0]);
            $("#dss-interactive-slider-ptk-end-label").text(ptks[ptks.length - 1]);
        }

        function setDisabledRegions() {
            var missingValue = null,
                leftCount = 0, rightCount = 0,
                leftWidth, rightWidth,
                l = stks.length,
                i;

            for (i = 0; stks[i] === missingValue && i < l; i++) {
                leftCount++;
                
            }
            for (i = l - 1; stks[i] === missingValue && i >= 0; i--) {
                rightCount++;
            }

            leftWidth = determineSliderOffset(leftCount, l);
            rightWidth = determineSliderOffset(rightCount, l);

            $("#dss-interactive-slider-region-disabled-left").css("width", leftWidth + "%");
            $("#dss-interactive-slider-region-disabled-right").css("width", rightWidth + "%");
        }

        function findValidStkIndex() {
            var l = stks.length,
                i;
            // scan forward first incase missing element is at front
            for (i = currentStkIndex; i < l; i++) {
                if (stks[i] !== null) {
                    return i;
                }
            }
            for (i = l - 1; i >= 0; i--) {
                if (stks[i] !== null) {
                    return i;
                }
            }
        }

        function ptkSlideHandler(event) {
            var ptk, stk,
                popupText;

            currentPtkIndex = event.args.value;

            ptk = ptks[currentPtkIndex];
            stks = getStks(ptk);

            if (currentStkIndex >= stks.length || stks[currentStkIndex] === null) {
                stk = stks[findValidStkIndex()];
            } else {
                stk = stks[currentStkIndex];
            }

            setImg(dsmn, ptk, stk);
	    setPtkSliderPopup(ptkPopupSelector, ptk, stk, getFrequency(dsmn), this, ptks.length, currentPtkIndex);
            configStkSlider();
        }

        function ptkSlideStartHandler(event) {
            unbindStkEvents();
            dismissPermalink();
	    setPtkSliderPopup(ptkPopupSelector, ptks[currentPtkIndex], stks[currentStkIndex], getFrequency[dsmn], this, ptks.length, event.args.value);
	    $(ptkPopupSelector).addClass("dss-interactive-slider-popup-active");
            //            hideElements();
        }

        function ptkSlideEndHandler(event) {
            bindStkEvents();
	    $(ptkPopupSelector).removeClass("dss-interactive-slider-popup-active");
            currentStkIndex = findValidStkIndex();
            if (determineStkDisabled() === false) {
                switchDataSnapshotContent(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
            } else {
                switchDataSnapshotContent(dsmn, ptks[currentPtkIndex]);
            }
            //            showElements();
        };

        function bindPtkEvents() {
            $('.field-name-field-ds-ptk > .field-items')
                .bind('slide', ptkSlideHandler)
                .bind('slideStart', ptkSlideStartHandler)
                .bind('slideEnd', ptkSlideEndHandler);

            /*
              $('.field-name-field-ds-ptk > .field-items').bind('change', function(event) {
                currentPtkIndex = event.args.value;
                stks = getStks(ptks[currentPtkIndex]);
                setImg(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
                configStkSlider();
                })
            */
        }

        function unbindPtkEvents() {
            $('.field-name-field-ds-ptk > .field-items')
                .unbind('slide', ptkSlideHandler)
                .unbind('slideStart', ptkSlideStartHandler)
                .unbind('slideEnd', ptkSlideEndHandler);
        }

        function configPtkSlider() {
            $('.field-name-field-ds-ptk > .field-items').jqxSlider({ 
                theme: 'ui-darkness',
                min: 0,
                max: ptks.length - 1,
                ticksFrequency: 1,
                value: currentPtkIndex,
                step: 1,
                showButtons: false,
                ticksPosition: 'bottom',
                width: 380,
                height: 17,
                showRange: false,
                mode: 'fixed',
                tooltip: false
                        });

            /*
            $('#dss-interactive-slider-ptk-slider').slider({
                'min' : 0,
                'max' : ptks.length - 1,
                'value' : currentPtkIndex,
            });
            replaceTickmarks();
            */
        };

        function stkSlideHandler(event) {
            var newStkIndex = event.args.value;
            if (stks[newStkIndex] === null) {
                return false;
            }
            var ptk, stk;
            currentStkIndex = event.args.value;

            ptk = ptks[currentPtkIndex];
            stk = stks[currentStkIndex];

            setImg(dsmn, ptk, stk);
	    setSliderPopups(stkPopupSelector, ptk + "-" + stk, this, stks.length, currentStkIndex);
        }

        function stkSlideStartHandler(event) {
            dismissPermalink();
	    setSliderPopups(stkPopupSelector, ptks[currentPtkIndex] + "-" + stks[currentStkIndex], this, stks.length, event.args.value);
	    $(stkPopupSelector).addClass("dss-interactive-slider-popup-active");
	    //	    hideElements();
        }

        function stkSlideEndHandler(event) {
	    $(stkPopupSelector).removeClass("dss-interactive-slider-popup-active");
            switchDataSnapshotContent(dsmn, ptks[currentPtkIndex], stks[currentStkIndex]);
	    //	    showElements();
        }

        function bindStkEvents() {
            $('.field-name-field-ds-stk > .field-items').bind('slide', stkSlideHandler)
                .bind('slideStart', stkSlideStartHandler)
                .bind('slideEnd', stkSlideEndHandler);
        }

        function unbindStkEvents() {
            $('.field-name-field-ds-stk > .field-items').unbind('slide', stkSlideHandler)
                .unbind('slideStart', stkSlideStartHandler)
                .unbind('slideEnd', stkSlideEndHandler);
        }

        function configStkSlider() {
            //            setDisabledRegions();

            $('.field-name-field-ds-stk > .field-items').jqxSlider({ 
                theme: 'ui-darkness',
                min: 0,
                max: stks.length - 1,
                ticksFrequency: 1,
                value: findValidStkIndex(),
                step: 1,
                showButtons: false,
                ticksPosition: 'top',
                width: 380,
                height: 17,
                showRange: false,
                mode: 'fixed',
                tooltip: false
            });

            /*
            $('#dss-interactive-slider-stk-slider').slider({
                'min' : 0,
                'max' : stks.length - 1,
                'value' : findValidStkIndex()
            });

            replaceTickmarks();
            */
        }

        function dataSourceStkChange() {
            //            $('#dss-interactive-slider-stk-slider').slider("option", "disabled", determineStkDisabled());
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
                // Note: dsmn is the machine name of the currently selected data source; it's a local
                // var declared inside `$('document').ready(function()` above.
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
	    $(".dss-data-source-dropdown.active").removeClass("active");
            unbindPtkEvents();
            unbindStkEvents();
            setDataSource($(this).attr("value"));
            dismissPermalink();
	    $(this).addClass("active");
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
            $(".dss-short-summary-text").text($(".field_dssds_framing_q_answer").text().split(".")[0] + ".");
            bindPtkEvents();
            bindStkEvents();
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
