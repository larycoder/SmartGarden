# Smart Garden
Client Pi Code

These code apply python to implement service. It does 2 steps:

- Cron data from arduino (UART)
- Then send data back to USTHServer (HTTP)

These file could run directly with command:
```
python main.py
```

| file | description |
|:------|-------------|
| lib | library directory allowing Pi to communicate with arduino |
| lora.py | lora handler |
| server.py | USTH server handler |
| config.py | Load system config |
| main.py | Main script to run app |
| example, old | skipped directory - for dev only |
| .env | default json environment values |
