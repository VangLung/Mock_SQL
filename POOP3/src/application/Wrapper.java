package application;

public class Wrapper {
	
	static {
		System.loadLibrary("Dll");
	}

	public native String exec(String query);

}
