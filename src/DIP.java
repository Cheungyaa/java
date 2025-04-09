interface Switchable {
    void turnOn();
    void turnOff();
}

class LightBulb implements Switchable {
    public void turnOn() {
        System.out.println("LightBulb: turned on");
    }

    public void turnOff() {
        System.out.println("LightBulb: turned off");
    }
}

class Fan implements Switchable {
    public void turnOn() {
        System.out.println("Fan: turned on");
    }

    public void turnOff() {
        System.out.println("Fan: turned off");
    }
}

class ElectricPowerSwitch {
    private Switchable device;

    public ElectricPowerSwitch(Switchable device) {
        this.device = device;
    }

    public void press() {
        System.out.println("Power Switch pressed");
        device.turnOn();
    }
}