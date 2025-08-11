# Progress Bar API
**For mods to easily create progress bars.**

> ![icon](frame:geode.loader/info-warning.png?scale=0.375) <cy>*This mod is no longer being maintained.*</c>

*by* ***[Cheeseworks](user:6408873)****!*

> ![icon](frame:GJ_infoIcon_001.png?scale=0.5) <cj>*This mod is an API for other mods to depend on.*</c>

> ![icon](frame:collaborationIcon_001.png) <cg>*This mod has settings you can utilize to customize your experience.*</c>

---

## About
This mod has an API that other mod developers can use to easily create customizable progress bars for their own purposes.

---

### API
Here's some basic information on the classes that this mod provides. You can find more information and code examples on the class and its fields & methods in the header file or README inside the API's folder.

#### `ProgressBar`
```cpp
static ProgressBar* create(); // Create the custom progress bar

void setBarColor(ccColor3B color); // Set the color of the fill of the bar
void updateBar(float value); // Update the fill of the bar

float getProgress(); // Get the current progress of the bar
```