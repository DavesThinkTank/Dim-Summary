**Bally Pinball with Arduino Running the RPU Operating System**

I was recently reviewing some old code, imported into my Flash Gordon pinball machine years ago, and noticed it made use of the light-dimming capability of the RPU operating system. The way this works, as I understand, is it turns the lights off very quickly for brief moments, faster than the human eye can follow. This ought to work fine with incandescent bulbs, but whether or not LEDs would work was not so obvious. I wrote this program in order to test the result.

The short story is, dimming level 1 appears to work fine. However, levels 2 and 3 are a flickering mess! This program is made available for anyone who wishes to test their own pinball machine, with their own bulbs.
