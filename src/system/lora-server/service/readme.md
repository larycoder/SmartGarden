## Copy the script to /usr/bin and make it executable:
```bash
sudo cp lora_service.sh /usr/bin/lora_service.sh
sudo chmod +x /usr/bin/lora_service.sh
```

## Create a Unit file to define a systemd service:
 /lib/systemd/system/lora.service 

## Start and Enable the ServicePermalink
```bash
sudo systemctl start lora
sudo systemctl enable lora
sudo systemctl status lora
```