package net.emo;

public class State {
	public static final int AUTONOMOUS = 0;
	public static final int MANUAL = 1;
	public static final int REMOTE = 2;
	public static final int EXPLORE = 3;
	public static final int STANDBY = 4;
	
	// Class to represent the state of emo
	int mode;
	int battery;
	boolean moving;
	
	public int getMode() {
		return mode;
	}
	public void setMode(int mode) {
		this.mode = mode;
	}
	public int getBattery() {
		return battery;
	}
	public void setBattery(int battery) {
		this.battery = battery;
	}
	public boolean isMoving() {
		return moving;
	}
	public void setMoving(boolean moving) {
		this.moving = moving;
	}
	
}
