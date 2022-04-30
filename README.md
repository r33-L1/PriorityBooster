# PriorityBooster

Simple Driver and user-land client to chenge Thread priority.

## Usage

To install driver (you may need to turn on test signing: `bcdedit /set testsigning on` and reload) 
```
sc create boostdriver type= kernel binpath=<PATH_TO_PRIORITYBOOSTER.sys>
sc start boostdriver
```

Client
```
Booster.exe <threadid> <priority>
```

Priority should be 0 < Priority < 32
