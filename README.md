# [<img src="logo.png" width="30" alt="The mod's logo." />](https://www.geode-sdk.org/mods/cheeseworks.progressbarapi) Progress Bar API
For mods to easily create progress bars.

> [!WARNING]
> *This mod is no longer being maintained.*

---

> [<img alt="YouTube" src="https://img.shields.io/youtube/channel/subscribers/UCi2M6N_ff1UC6MyfWzKQvgg?style=for-the-badge&logo=youtube&logoColor=ffffff&label=YouTube">](https://www.youtube.com/@cheese_works/) [<img alt="Bluesky" src="https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fpublic.api.bsky.app%2Fxrpc%2Fapp.bsky.actor.getProfile%2F%3Factor%3Dcheeseworks.gay&query=%24.followersCount&style=for-the-badge&logo=bluesky&logoColor=ffffff&label=Bluesky">](https://bsky.app/profile/cheeseworks.gay) [<img alt="Discord" src="https://img.shields.io/discord/460081436637134859?style=for-the-badge&logo=discord&logoColor=ffffff&label=Discord">](https://dsc.gg/cubic)

> [<img alt="Latest Version" src="https://img.shields.io/github/v/release/BlueWitherer/ProgressBarAPI?include_prereleases&sort=semver&display_name=release&style=for-the-badge&logo=github&logoColor=ffffff&label=Version">](../../releases/) [<img alt="Code License" src="https://img.shields.io/github/license/BlueWitherer/ProgressBarAPI?style=for-the-badge&logo=gnu&logoColor=ffffff&label=License">](LICENSE.md)
>  
> [<img alt="Downloads" src="https://img.shields.io/github/downloads/BlueWitherer/ProgressBarAPI/total?style=for-the-badge&logo=geode&logoColor=ffffff&label=Downloads">](https://www.geode-sdk.org/mods/cheeseworks.progressbarapi)

> [!NOTE]
> *This mod is an API for other mods to depend on.*

> [!TIP]
> *This mod has settings you can utilize to customize your experience.*

---

## About
This mod has an API that other mod developers can use to easily create customizable progress bars for their own purposes.

---

### API
Here's some basic information on the classes that this mod provides. You can find more information and code examples on the class and its fields & methods in the header file or README inside the API's folder.

#### `ProgressBar`
```cpp
static ProgressBar* create(); // Create the custom progress bar

void setProgressBarFillColor(ccColor3B color); // Set the color of the fill of the bar
void updateProgress(float value); // Update the fill of the bar

float getProgress(); // Get the current progress of the bar
```

---

### Changelog
###### What's new?!
**[📜 View the latest updates and patches](./changelog.md)**

### Issues
###### What's wrong?!
**[⚠️ Report a problem with the mod](../../issues/)**

### Development
###### Work with the mod directly.
**[⌨️ Check the API out](./incl/)**