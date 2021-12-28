package hcm;

import net.emo.State;
import net.emo.comm.SerialComm;

public class HardwareControlModule {
	SerialComm serial;
	State state;

	public HardwareControlModule() {
		serial = new SerialComm();
		state = new State();
	}
	
	public void init() {
		System.out.println("[HCM] Initializing serial communication");
		serial.init();
	}

	public SerialComm getSerial() {
		return serial;
	}

	public void setSerial(SerialComm serial) {
		this.serial = serial;
	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}
	
	
}
