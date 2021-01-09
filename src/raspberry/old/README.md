# Smart Garden
Client Pi Code

These code apply python to implement service. It does 2 steps:

- Cron data from arduino (UART)
- Then send data back to USTHServer (HTTP)

These file could run directly with command:
```
python {UART}_connect_client.py
```

| file | description |
|:------|-------------|
| lora_connect_client | lora protocol |
| wire_connect_client | wire & zigbee protocol |