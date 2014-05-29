<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1"/>

    <title>Data Snapshot Widget test 2</title>

    <link rel="stylesheet" href="css/jqx.base.css" type="text/css" />
    <link rel="stylesheet" href="css/jqx.ui-darkness.css" type="text/css" />
    <link rel="stylesheet" href="css/custom-theme/jquery-ui-1.10.4.custom.min.css" type="text/css" media="all" />
    <link rel="stylesheet" href="css/datSnapStyles.css" type="text/css" media="all" />  

    <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script>
    <script src="http://ajax.googleapis.com/ajax/libs/jqueryui/1.10.4/jquery-ui.js" type="text/javascript"></script>

    <script type="text/javascript" src="ui/jqwidgets/jqxcore.js"></script>
    <script type="text/javascript" src="ui/jqwidgets/jqxbuttons.js"></script>
    <script type="text/javascript" src="ui/jqwidgets/jqxcheckbox.js"></script>
    <script type="text/javascript" src="ui/jqwidgets/jqxbuttongroup.js"></script>
    <script type="text/javascript" src="ui/jqwidgets/jqxradiobutton.js"></script>
    <script type="text/javascript" src="ui/jqwidgets/mods/sliderMod.js"></script>
    <script type="text/javascript" src="js/datSnapMenuFunctions.js"></script>

    <style>
      @font-face {
        font-family:widgeTitleFont;
        src: url(fonts/Cabin/Cabin-Bold.ttf)
      }

      #accordion .ui-icon { display: none; }
    </style>

  </head>			
  <body>

    <div id="backgroundHolder">

      <svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" 
	   width="941px" height="600px" viewBox="0 0 941 600" enable-background="new 0 0 941 600" xml:space="preserve">

	<path fill="#404952" stroke="#B8BABC" stroke-miterlimit="10" d="M936,583.5c0,5.522-4.478,10-10,10H16c-5.522,0-10-4.478-10-10V16
				                                        c0-5.523,4.478-10,10-10h910c5.522,0,10,4.477,10,10V583.5z"/>

	<path fill="#DADBDC" d="M922,13.662h-69c0,0-148.303,0-158,0c-22,0-11,40-49.632,39.903l-0.069,468.273H928V135.341V19.662
				C928,16.349,925.313,13.662,922,13.662z"/>

	<rect x="14" y="53.662" fill="#FFFFFF" width="631.299" height="468.176"/>
	
	<rect x="18.216" y="58.028" fill="#FFFFFF" width="625.07" height="2.795"/>
	
	<path fill="#303841" d="M642.5,572.882c0,5.522-4.478,10-10,10H26c-5.522,0-10-4.478-10-10v-30.355c0-5.522,4.478-10,10-10h606.5
				c5.522,0,10,4.478,10,10V572.882z"/>
      </svg>

      <div id="contentHolder">

        <!-- Top Holder Start -->
	<div id="topHolder">
	  <div id="topLeftHolder">
	    <div id="widgTitle">Data Snapshots</div>
	  </div>
	  <div id="topRightHolder">
	    <div id='descMapButtGrp'>
              <button id="descriptButt">Maps</button>
              <button id="mapButt">Description</button>
	    </div>
	  </div>
	</div>
        <!-- Top Holder End -->
		
        <!-- Middle Holder Start -->
	<div id="middleHolder">
	  <div id="middleLeftHolder">
	    <img id="mapHold"></img>
	    <div id="downloadPop">
	      <div id="downloadPopCont">
		<div id="DL_RadButtHold" style='margin-top: 20px; margin-left:30px; float:left; width=150px;'>
		  <div  id='DL_RadioButton_620'>Small</div>
       		  <div style='margin-top: 0px;' id='DL_RadioButton_1000'>Large</div>
       		  <div style='margin-top: 0px;' id='DL_RadioButton_1920'>High Definition</div>  
       		  <div style='margin-top: 0px;' id='DL_RadioButton_1920SD'>HD w/SD Title Safe</div>
		  <div style='margin-top: 0px;' id='DL_RadioButton_Full'>Full Resolution Assets</div>
		</div>
		<div id="DL_SizeLabelHold" style='margin-top: 20px; margin-left:25px; float:left;'>
		  <div id="labelOne">620px</div>
		  <div id="labelTwo">1000px</div>
		  <div id="labelThree">1920px</div>
		  <div id="labelFour">1920px</div>
		  <div id="labelFive">4096px</div>
		</div>
	      </div>
	      <div id="popLabel">Select a Format:</div>
	      <div id="popButtHold" style="margin-top:10px; margin-right:20px;float:right;">
		<input type="button" value="Cancel" id='cancelButt' />
		<input type="button" value="OK" id='okButt' />
	      </div>
	    </div>
	  </div>
	  <div id="middleRightHolder">
	    <div id="maintextHolder">
	      <div id="descTitle"></div>
	      <div id="topText"></div>
	      <div id="bottomText"></div>
	      <div id="botTextReadLab">read more&gt;&gt;</div>
	    </div>
	    <div id="mapMenHold">
	      <div id="mapMenuSpacer"></div>
	      <div id="accordion">
		<H3 style="padding-top:3px; padding-bottom:5px; font-size:14px;">Temperature</H3>
		<div id="DS_MenuSelector0"></div>
		<H3 style="padding-top:3px; padding-bottom:5px; font-size:14px;">Precipitation</H3>
		<div id="DS_MenuSelector1"></div>
		<H3 style="padding-top:3px; padding-bottom:5px; font-size:14px;">Outlooks</H3>
		<div id="DS_MenuSelector2"></div>
		<H3 style="padding-top:3px; padding-bottom:5px; font-size:14px;">Drought</H3>
		<div id="DS_MenuSelector3"></div>
		<H3 style="padding-top:3px; padding-bottom:5px; font-size:14px;">Severe Weather</H3>
		<div id="DS_MenuSelector4"></div>
	      </div>
	    </div>
	    <div id="aboutSnapPanelHolder">
	      <div id='aboutSnapbacker'>
		<div id='aboutSnapTitle'>About This Snapshot:</div>
		<div id='aboutSnapPar'></div>						
	      </div>				
	    </div>
	    <div id="aboutDatePanelHolder">
	      <div id='bottomer'>
		<div id='aboutTitle'>About This Date:</div>
		<div id='aboutPar'></div>						
	      </div>
	      <div id='moreAboutLab'>read more&gt;&gt;</div>
	      <div id='topper'></div>					
	    </div>
	  </div>
	</div>
        <!-- Middle Holder End -->
	
        <!-- Bottom Holder Start -->
	<div id="bottomHolder">
	  <div id="bottomLeftHolder">
	    <div id="slidLabHolder">
	      <div id="topSlidLab">Months:</div>
	      <div id="botSlidLab">Years:</div>
	    </div>
	    <div id="slidLeftValLabHolder">
	      <div id="topLeftValSlidLab">Jan</div>
	      <div id="botLeftValSlidLab">1984</div>
	    </div>
	    <div id="sliderHolder">
	      <div id="monthSlider"></div>
	      <div id="yearSlider"></div>	
	    </div>
	    <div id="slidRightValLabHolder">
	      <div id="topRightValSlidLab">Dec</div>
	      <div id="botRightValSlidLab">2014</div>
	    </div>
	    <div id="dlButtHolder">
	      <input type="button" value="Download" id='downloadButt' />
	    </div>
	  </div>
	  <div id="bottomRightHolder">
	    <div id="socMedTempHold" style="width:245px; height:20px; float:right; margin-right:6px; margin-top:3px;">
	      <img id="socMedImage" src="media/uiGraphics/sociMedGraphic.png"></img>
	    </div>
	  </div>
	</div>
        <!-- Bottom Holder End -->
      </div>
    </div>

  </body>
</html>
