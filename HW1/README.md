# Design Doc

**BUILD & TESTED ON WINDOWS 11 ONLY**

I'm attempting to immitate the Unity Console, so the state changes came easy.
I opted to make the code more simplistic over optimal performance because this is a debug tool, and will not be included in release versions of any software.

## Saving Logs
Something that quickly becomes even more helpful than errors in a nice GUI console, is to save them to a file. I hate it when files get overwritten, so I like to save my logs with names that are unlikely to be overwritten. I considered GUIDs, but instead opted to go with something that might actually be useful. The convention I decided to go with is `StartTime_EndTime.log`. This also works fine for if the user wants to save multiple versions of the log at different times, since those end times will be different. If the Logger is killed, it automatically saves the log up to that point. formatTime could use some optimisations: creating and destroying a ostringstream over and over is pretty wasteful. I've heard making it static could help, but that's a little less safe, and I'm not sure about best practice for that. I doubt I'd want to multi-thread this program since it's fairly basic

## GUI
As stated above, the goal is to imitate Unity's console. So, large icon to the left for easily identification, an hourly timestamp, and the message. Ideally, we'd also include the location in the code where this log is sent, but idk how to do that just yet haha. Icons turned out to be tricker than I thought to implement and I opted to save my sanity and try that when I don't have a looming deadline. For the mean time though, this works good enough. Originally it sort of annoyed me that ImGui didn't come pre-bundled with an image rendering system, but then I realised that it's kind of genious. To be truly cross-platform, self-dependant and light weight, an image loader just isn't neccesary. The programmer can choose their favourite system specific library and integrate it with ImGui, as long as that library can integrate with OpenGL. It's pretty genius.

Generally, I subscribe to the philosophy that any programmer who will use your code will not read any of the documentation the first time they try to use it. So, I opt to make most things private unless *absolutely neccesary*. I wanted the log class to manage its own window so all the user has to do is include it and it'll work.

For the "setLevel" function; I interpretted that as a visiblity function. I originally opted for a drop-down, but decided I'd rather imitate Unity's style of clicking to toggle certain styles. I opted for a bitmasking system to efficiently manage this; also fairly extendable if I decided to add new levels.

I also don't enjoy when programs auto scroll me to the newest update if i'm not at the bottom. I want to view what I'm looking at, damn it! So, you're only auto scrolled if you're at the bottom of the scrolling area.