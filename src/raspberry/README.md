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
| lora.py | lora handler |
| server.py | USTH server handler |
| config.py | Load system config |
| .env | default json environment values |
