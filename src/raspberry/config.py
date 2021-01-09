# Import credential from .env file and load it to dict
import json

config = {}
try:
    with open(".env", "r") as env_file:
        config =  json.load(env_file)
except Exception as e:
    print("Something wrong happen with message:\n" + str(e))

if __name__ == '__main__':
    print("This file return config from env:")
    print(json.dumps(config))
