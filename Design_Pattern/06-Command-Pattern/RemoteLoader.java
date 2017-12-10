public class RemoteLoader {
    public static void main(String[] args) {
        RemoteControl remote = new RemoteControl();
        Light livingRoomLight = new Light("Living Room");
        Light kichenLight = new Light("Kitchen");
        /*
        CeilingFan ceilingFan = new CeilingFan("Living Room");
        GarageDoor garageDoor = new GarageDoor("");
        Stereo stereo = new Stereo("Living Room");
        */

        LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
        LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);
        LightOnCommand kichenLightOn = new LightOnCommand(kichenLight);
        LightOffCommand kichenLightOff = new LightOffCommand(kichenLight);
        /*
        CeilingFanOnCommand ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
        CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceilingFan);
        GarageDoorUpCommand garageDoorUp = new GarageDoorUpCommand(garageDoor);
        GarageDoorDownCommand garageDoorDown = new GarageDoorDownCommand(garageDoor);
        StereoOnWithCDCommand stereoOnWithCD = new StereoOnWithCDCommand(stereo);
        StereoOffCommand stereoOff = new StereoOffCommand(stereo);
        */
        remote.setCommand(0, livingRoomLightOn, livingRoomLightOff);
        remote.setCommand(1, kichenLightOn, kichenLightOff);
        /*
        remote.setCommand(2, ceilingFanOn, ceilingFanOff);
        remote.setCommand(3, garageDoorUp, garageDoorDown);
        remote.setCommand(4, stereoOnWithCD, stereoOff);
        */

        System.out.println(remote.toString());

        remote.onBottonWasPressed(0);
        remote.offBottonWasPressed(0);
        remote.onBottonWasPressed(1);
        remote.offBottonWasPressed(1);
        /*
        remote.onBottonWasPressed(2);
        remote.offBottonWasPressed(2);
        remote.onBottonWasPressed(3);
        remote.offBottonWasPressed(3);
        remote.onBottonWasPressed(4);
        remote.offBottonWasPressed(4);
        */
    }
}
