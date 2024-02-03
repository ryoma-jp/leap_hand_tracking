# Hand Tracking Sample for LeapMotion

This program is modified from LeapSDK sample (PollingSample), add to print bone points of each finger.

## Environment

|Item|Description|
|---|---|
|OS|Windows 11 Home|
|Version|23H2|
|OS Build|22635.3130|
|Processor|Intel(R) Core(TM) i7-10700F CPU @ 2.90GHz 2.90 GHz|
|RAM|32GB|

## Build

Launch PowerShell and run following commands.

```
> $env:BUILD_TYPE = 'Release'
> mkdir build
> $env:REPOS_BUILD_ROOT = './build'
> $env:REPOS_INSTALL_ROOT = 'C:/Program Files'
> cmake -S "./src" -B $env:REPOS_BUILD_ROOT/$env:BUILD_TYPE/LeapSDK/PollingSample -DCMAKE_INSTALL_PREFIX="$env:REPOS_INSTALL_ROOT/PollingSample" -DCMAKE_BUILD_TYPE="$env:BUILD_TYPE"
> cmake --build $env:REPOS_BUILD_ROOT/$env:BUILD_TYPE/LeapSDK/PollingSample -j --config $env:BUILD_TYPE
```

## Run

Launch PowerShell and run following commands.

```
> .\build\Release\LeapSDK\PollingSample\Release\PollingSample.exe
Connected.Using device LP42563219022.
Frame 13459 with 1 hands.
    Hand id 38 is a left hand with position (-64.797859, 246.707794, 16.992355).
        Thumb:
            id: 0
            bone[0]: base(-91.133659, 241.888748, 65.009972) -> end(-91.133659, 241.888748, 65.009972)
            bone[1]: base(-91.133659, 241.888748, 65.009972) -> end(-47.805874, 245.781494, 62.818459)
            bone[2]: base(-47.805874, 245.781494, 62.818459) -> end(-23.347898, 248.223099, 63.738838)
            bone[3]: base(-23.347898, 248.223099, 63.738838) -> end(-6.898701, 249.323471, 62.594326)
        Index:
            id: 1
            bone[0]: base(-93.676407, 256.183929, 55.762794) -> end(-33.224335, 256.246918, 17.892492)
            bone[1]: base(-33.224335, 256.246918, 17.892492) -> end(-6.530300, 259.876434, 3.138434)
            bone[2]: base(-6.530300, 259.876434, 3.138434) -> end(11.486284, 259.824463, -6.346276)
            bone[3]: base(11.486284, 259.824463, -6.346276) -> end(26.791714, 258.267883, -13.713239)
        Middle:
            id: 2
            bone[0]: base(-97.274658, 256.251221, 46.566147) -> end(-45.345188, 254.924454, 3.231632)
            bone[1]: base(-45.345188, 254.924454, 3.231632) -> end(-18.572144, 260.142975, -22.617420)
            bone[2]: base(-18.572144, 260.142975, -22.617420) -> end(0.879988, 260.475037, -40.649250)
            bone[3]: base(0.879988, 260.475037, -40.649250) -> end(14.427938, 259.129425, -52.440987)
        Ring:
            id: 3
            bone[0]: base(-103.941399, 252.238602, 36.288857) -> end(-63.646683, 249.508240, -9.074807)
            bone[1]: base(-63.646683, 249.508240, -9.074807) -> end(-44.577480, 253.953903, -41.609726)
            bone[2]: base(-44.577480, 253.953903, -41.609726) -> end(-32.333912, 253.372467, -59.863441)
            bone[3]: base(-32.333912, 253.372467, -59.863441) -> end(-22.510294, 251.388672, -73.698296)
        Pinky:
            id: 4
            bone[0]: base(-112.231941, 243.168259, 32.919994) -> end(-81.384964, 241.572708, -14.058838)
            bone[1]: base(-81.384964, 241.572708, -14.058838) -> end(-77.560463, 242.904572, -39.848782)
            bone[2]: base(-77.560463, 242.904572, -39.848782) -> end(-72.845955, 240.520020, -59.050701)
            bone[3]: base(-72.845955, 240.520020, -59.050701) -> end(-68.680664, 237.484360, -72.351753)
```

## License

- See [Ultraleap Tracking SDK License Agreement](https://central.leapmotion.com/agreements/SdkAgreement).
- Modified part is MIT License
