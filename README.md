# Generate Client Interface
```sh
protoc --dart_out=arduino_interface_client .\arduino.proto
```

# Generate Server Interface
```sh
protoc --nanopb_out=include .\arduino.proto
```