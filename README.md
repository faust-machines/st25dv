# ST25DV driver module for Zephyr

### Setup
To add the driver to your Zephyr project, set `CONFIG_LIBST25DV=y` in your prj.conf, and then run `west update`

### DTS
Example of device tree :
```
&i2c2 {
    pinctrl-0 = <&i2c2_scl_pb13 &i2c2_sda_pb14>;
    pinctrl-names = "default";
    status = "okay";
    clock-frequency = <I2C_BITRATE_FAST>;

    st25dv: st25dv@a6 {
        compatible = "st,st25dv";
        reg = <0xa6>;
        interrupt-gpios = <&gpiob 15 GPIO_ACTIVE_LOW>;
        status = "okay";
    };
};
```