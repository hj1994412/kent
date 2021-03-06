/* Copyright (C) 2014 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#include "common.h"
#include "hgConfig.h"
#include "hPrint.h"
#include "googleAnalytics.h"


void googleAnalytics()
/* check for analytics configuration item and output google hooks if OK */
{
static boolean done = FALSE;

if (done)
    return;

done = TRUE;	/*	do not repeat this by mistake	*/

char *analyticsKey = cfgOption("analyticsKey");

/*	if config is missing or empty, nothing happens here	*/
if (isEmpty(analyticsKey))
    return;

/* updated to Universal Analytics code 2014-06-19 */

jsInlineF(
"  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){\n"
"  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),\n"
"  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)\n"
"  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');\n"
"  ga('create', '%s', 'auto');\n"
"  ga('require', 'displayfeatures');\n"
"  ga('set', 'transport', 'beacon');\n"
"  ga('send', 'pageview');\n"
"\n"
, analyticsKey);
// see https://support.google.com/analytics/answer/1136920?hl=en
jsInlineF(
"  function anchorClicked(ev) {\n"
"  /* user clicked an anchor: send event to Google analytics and navigate to the link */\n"
"      var isExternal = (ev.target.target==='_blank');\n"
"      var url = ev.target.href;\n"
"      if (url === undefined)\n" // this happens on hgTracks, for the case <a href....><p>bla</p></a>
"           url = ev.target.closest('a');\n"
"      if (isExternal) {\n"
"         ga('send', 'event', 'outbound', 'click', url,\n"
"           { 'transport': 'beacon', 'hitCallback': function(){window.open(url);} });\n"
"      } else {\n"
"         document.location=url;\n"
"      }\n"
"      return false;\n"
"  }"
"  $(document).ready(function() {\n"
"      if (!window.ga || ga.loaded)\n"
"          return;\n"
"      var anchors = document.getElementsByTagName('a');\n"
"      for (var i = 0; i < anchors.length; i++) { \n"
"           var a = anchors[i];\n"
"           if (a.attributes.href && a.attributes.href.value!=='#')\n" // do not run on javascript links
"               a.onclick = anchorClicked;"
"      };\n"
"      // on hgTracks: send an event with the current db, so we can report popularity of assemblies to NIH\n"
"      if (typeof hgTracks !== undefined)\n"
"          ga('send', 'event', 'hgTracks', 'load', getDb());\n"
"  });"
);

}
