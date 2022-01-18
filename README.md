
<br />
<div align="center">
  <a href="https://github.com/Jax-Core/IdleStyle">
    <img src="https://imgur.com/rBXxbzz.png" alt="Logo" width="200" height="200">
  </a>

<h3 align="center">IdleStyle</h3>

  <p align="center">
    Stylized screensavers.
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/IdleStyle-Stylized-Screensaver-899004964"><strong>More Info »</strong></a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features </a>
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
    </li>
    <li>
      <a href="#Features">Features</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li>
    <a href="#custom-animations-setup">Custom Animations Setup</a>
    <ul>
        <li><a href="#static-backgrounds">Static Backgrounds</a></li>
        <li><a href="#video-backgrounds">Video Backgrounds</a>
          <ul>
            <li><a href="#installing-ffmpeg">Installing FFMPEG</a></li>
            <li><a href="#setting-up-the-video-background">Setting up the video background</a></li>
          </ul>
        </li>
    </ul>
    </li>
    <li> <a href="#help-and-credits">Help & Credits</a></li>

  </ol>
</details>


## About

![IdleStyle](https://user-images.githubusercontent.com/80020581/143574887-e6e32c3d-3100-4ad8-91d8-f1f8cb612ced.png)

IdleStyle is a Rainmeter skin that offers fully customizable screensavers with custom animation support. Custom animations can be used to display a range of things such as skins, images, and videos. If you want people to notice the fancy side of your desktop, this is a must-have!

## Features

* Flawless Custom Animations
* Light Weight and Easy Manipulation
* Customizable Skin Groups
* Multiple Monitor Support

## Getting Started

### Prerequisites

- **Rainmeter v4.5 or newer.** Rainmeter can be installed by downloading the `.exe` file [from Rainmeter's official website.](https://www.rainmeter.net/)
- **JaxCore v40005.** JaxCore can be installed by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Installation

Assuming you successfully downloaded and installed Rainmeter as well as JaxCore, you can now proceed to install IdleStyle by following the steps below.

1. Download and run the `.rmskin` file for **IdleStyle** from the official [JaxCore site](https://jax-core.github.io/) to install **IdleStyle**.
2. Leave the installation settings at their defaults and click Install.
3. When the installation is finished, a startup pop-up should appear. Follow through the pop-up to finish installing **IdleStyle**.

* Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

## Custom Animations Setup

Now that you've installed and setup IdleStyle, let's begin setting up some custom animations it comes with!

### Static Backgrounds

1. Open Core and head over to the **Modules** section.
2. Select **IdleStyle** from the list and proceed to the **Animation** tab.
3. Enable the custom background preset all the way at the bottom.
3. Go to **Appearance** tab and under **Customization** press the `DefaultPaper` button besides the `Wallpaper Path` text.
4. Select the custom background you would like to use. **Please select common file formats such as `.jpg` or `.png`**
5. Refresh **IdleStyle** by deactivating and activating the toggle on the bottom left.

The background of your screen saver has now been changed. 

### Video Backgrounds

#### Installing FFMPEG

To use video backgrounds, you must first install and configure **[ffmpeg](https://github.com/BtbN/FFmpeg-Builds/releases).** If you already have FFMPEG installed, you can skip this step; if not, follow the instructions below.

1. Open [this link](https://github.com/BtbN/FFmpeg-Builds/releases/download/latest/ffmpeg-master-latest-win64-gpl.zip). This link will download a zipped file named `ffmpeg-master-latest-win64-gpl.zip`
2. Extract the zipped file you just downloaded and open the `ffmpeg-master-latest-win64-gpl` folder. Inside, you will find another folder with the same name which we will be renaming in the next step.
3. Rename the folder to `ffmpeg`. **Please rename it as directed and do not make any changes to the folder name.**
4. Copy the entire folder (`CTRL + C`) 
5. Open File Explorer and navigate to `C:\`; your Windows Drive. The Windows Drive is typically the `C:` drive, but it may differ for you, so please double-check and navigate to the correct drive.
5. Paste the folder in the `C:\` drive.
6. Open the `ffmpeg` folder you just pasted and go into the `bin` folder.
7. Now, copy the file location by clicking on the top bar that displays it. If your Windows drive is the C drive, the path should be `C:\ffmpeg\bin`. However, if your Windows Drive is something other than **C:**, the file location will be in accordance with the Windows Drive.
8. You can now exit out of File Explorer.
9. Open Run(`Win + R`), paste in `rundll32.exe sysdm.cpl,EditEnvironmentVariables` and press **OK**. This will open a new dialogue box in which we will make the remaining changes.
10. Under the `User variables for yourusername` section, select `Path` and press **Edit**.
11. Once a new window appears, press **New** that will be on the right hand side, and paste in the file location you copied in **Step 7** i.e. `C:\ffmpeg\bin`.
12. Press **OK** and then **OK** again and exit out of everything.

#### Setting up the video background
And that is how you setup FFMPEG. You can now proceed to configure the video backgrounds for IdleStyle. **Simply follow the steps outlined below:**

1. Open Core and head over to the **Modules** section.
2. Select **IdleStyle** from the list and proceed to the **Animation** tab.
3. Second from the bottom, enable the custom video background preset.
3. Go to **Appearance** tab and under **Customization** press the `DefaultVideo` button besides the `Video Path` text.
4. Choose the custom video background you want to use. **Please select common file formats such as `.mp4`**
5. Refresh **IdleStyle** by deactivating and activating the toggle on the bottom left.

The background of your screen saver has now been changed. 

**The other animations, on the other hand, do not necessitate the installation of any additional applications or extensions. So, you can simply enable them using the same method as described above for the Static Backgrounds animation.**

**You can also customize the color scheme for every animation as per need.**

## Help and Credits
- [IsFullScreen](https://forum.rainmeter.net/viewtopic.php?t=28305#p147499) plugin by jsmorley
- Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.
