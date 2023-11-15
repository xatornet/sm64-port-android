# sm64ex Android Port

Please, use Termux from GITHUB or F-Droid. Not from Google Play Store (obsolete)

**Install dependencies: (use this order or sdl2 won't install)**
```sh
pkg install x11-repo
pkg install git wget which make python getconf zip apksigner clang binutils mesa mesa-dev sdl2
```
**Update and Upgrade: (input YES to everything)**
```sh
pkg update -y
pkg upgrade -y
```

**Clone the repository:**
```sh
git clone https://github.com/xatornet/sm64-port-android --branch ex/nightly
cd sm64-port-android
```

**Copy in your baserom:**

Do this using your default file manager (on AOSP, you can slide on the left and there will be a "Termux" option there), or using Termux
```sh
termux-setup-storage
cp /sdcard/path/to/your/baserom.z64 ./baserom.us.z64
```

**Build:**
```sh
# if you have more cores available, you can increase the --jobs parameter
make TOUCH_CONTROLS=1 NODRAWINGDISTANCE=1 EXT_OPTIONS_MENU=1
```

**Enjoy your apk:**
```sh
ls -al build/us_pc/sm64.us.f3dex2e.apk
```

# Apply Patches

If you want to apply the 60fps patch or the DynOS patch, do it like this:

**Clean previously created build:**
```sh
make clean
```
**Apply DynOS patch with command:**
```sh
./tools/apply_patch.sh ./enhancements/DynOS.1.0.patch
```

**Apply 60fps patch with command:**
```sh
./tools/apply_patch.sh ./enhancements/60fps_ex.patch
```
**Build (DynOS requires EXTERNAL_DATA=1):**
```sh
# if you have more cores available, you can increase the --jobs parameter
make TOUCH_CONTROLS=1 NODRAWINGDISTANCE=1 EXT_OPTIONS_MENU=1 EXTERNAL_DATA=1
```
Now if you want to use this build, you have to add the base.zip to an external folder, as DynOS will need to read the content/resources externally.

**Download [base.zip](https://github.com/xatornet/sm64-port-android/blob/ex/nightly/base.zip) manually from this repo, and put it inside this folder (You have to use a PC to do this, unless you're rooted):**
```sh
/sdcard/Android/data/com.vdavid003.sm64port/files/res
```
With this, you are ready to play SM64.

## Adding DynOS model packs and/or Texture Packs

If you have built a DynOS version of the game, or some version with EXTERNAL_DATA=1, you can use DynOS model packs, and/or Texture Packs.

+ To add DynOS model packs:

Download them from [here](https://github.com/Render96/ModelPack/releases)

Decompress them into a folder
Then copy this folder manually from a PC to 
```sh
/sdcard/Android/data/com.vdavid003.sm64port/files/dynos/packs/
```
Now, open the game, an inside the DynOS menu, you should be able to select and enable the DynOS model pack.

+ To add Texture packs:

Download your prefered texture pack.
Then copy the zip/7z file manually from a PC to the same folder you already have the base.zip file:
```sh
/sdcard/Android/data/com.vdavid003.sm64port/files/res
```
Now, open the game and wait (it should be like a minute or so decompressing the new textures), if you have a blackscreen don't worry, it's normal. Give it time and the game should load eventually with the new texture pack enabled.
