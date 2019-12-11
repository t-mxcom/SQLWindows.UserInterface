# SQLWindows.UserInterface

This project contains a **User Interface Extension Library for OpenText Gupta Team Developer**, that was formerly published under the name *RACON.SQLWindows.UserInterface*.

***

**Important notice**

This repository is currently being set up and files will be added step-by-step.

So, if you see this notice and are interested in the content of this repository, please be patient! I'll remove this notice as soon as I finished my work on it!

THANK YOU!

***

## Introduction

The project was created, developed and maintained by me exclusively but because of changes in my working sphere, I nearly had no time to continue with it.
Because of this, and because of some other influencing factors, I now decided to stop this project.

As some of you might still use this component, let me please explain my desicion.

* The component was intentionally created as a temporary solution for gaining additional features offered by the [Prof-UIS](https://www.prof-uis.com/ "Jump to the Prof-UIS website!") library used by Team Developer, until all the featured found their way into Team Developer itself.

* As the developers of Team Developer needed to adapt the Prof-UIS library, it was necessary to link my component to the header (.h) and import library files (.lib), that exactly correspond to the Prof-UIS version shipped with Team Developer.

  * This required me to request the header and import library files for every RTM/PTF/Service Pack version of Team Developer, that I wanted to provide support for.

  * This required me to install each of the Team Developer versions and perform tests.

  * This required me to publish different component files (.dll) for each of the Team Developer versions.

  * This required you to use the appropriate version in your project.

* The component only worked for native (that is Win32 and Win64) but not for .NET/WPF applications.

* In addition, as Team Developer now supports native 64 bit applications, this would double the number of versions that I'd have to provide.

* Some of the features already found their way to Team Developer, so the useful parts of my component became less (as intended).

I hope you understand, that those facts led me to stop further support of this project!

## What if I still use this component?

I really understand, that reading the lines above is no fun for you if you rely on the component in your productive application.

For this reason, I discussed possible solutions with the developers of Team Developer. They also verified the possibility to takeover the maintainance of the component and ship it as part of the Team Developer deployment. Unfortunately, the answer was finally "No!"

After checking all possibilities and legal conditions, the final sulution is the repository you are looking at right now.

## What will I find in this repository?

* All the source code I wrote to build the component, but with some minor changes.

  * The original files contained some comments in German that I translated to English before adding the files here.

  * All references to the name *RACON* were removed. (see below for details)

  * All Team Developer internal files (headers and import libraries) only exist as placeholder files without actual content.

  * All files that are part of the Prof-UIS deployment only exist as placeholder files without actual content.

  * The samples reference libraries for [M!Table](http://www.micsto.de/ "Jump to the publishers website!") and [M!Image](http://www.micsto.de/ "Jump to the publishers website!") only exist as placeholder files without actual content.

* Solution and project files to be used with [Microsoft Visual Studio](https://visualstudio.microsoft.com/ "Jump to the Visual Studio website!"), but with some minor changes.

  * All references to the name *RACON* were removed. (see below for details)

* Please note, that the code contains a bunch of functions that I only used for experimenting. They are not finished and even may not work at all!

## Will I be able to build the component after cloning this repository?

Definitively **no!**

As mentioned above, some very important files are missing and I am not allowed to provide them in this repository!

* If you just want to run the samples and only need the M!Table and M!Image files, you can visit [www.micsto.de](http://www.micsto.de/ "Jump to the MICSTO website!"), where Michael Stoll provides his GREAT libraries for free!

* If you want to experiment with the component itself it may help to download the Prof-UIS SDK from [www.prof-uis.com](https://www.prof-uis.com/ "Jump to the Prof-UIS website!").
Please note, that different Team Developer versions use different Prof-UIS versions and you'll get the best results if you use matching versions.
Please also note, that the free Prof-UIS version supports fewer APIs as the purchased version (for example no ribbon APIs).

## What if I need one of the components functions in a newer Team Developer version?

Your first step should be to place a feature request either directly by contacting OpenText Gupta or via your Team Developer reseller.

Depending on your needs and your C/C++ development skills, you may also try to build your own component (see previous chapter). **But this can be really tricky and make your application really unstable or even crashing!!!**

## Support

To be short, there is none!
And to be honest, there never was one, as this was always a personal side-project for me which I maintained if I had enough time.

The company *RACON*, whose name was part of the components name in the past, enabled me to build, maintain and publish this component for you, which I'm really thankful for!

Now, they allowed me to open source the component for you as a reference, but only after removing the companies name (mentioned above as minor changes).

If you have any questions or want to give feedback, please e-mail me at [sqlwindows.userinterface@t-mx.com](mailto:sqlwindows.userinterface@t-mx.com "Send me e-mail on the SQLWindows.UserInterface component!").
