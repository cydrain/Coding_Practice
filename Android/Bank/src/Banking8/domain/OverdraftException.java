package Banking8.domain;

public class OverdraftException extends Exception {
	static final long serialVersionUID = -123456789L;
	private double deficit;

	public OverdraftException(String msg, double deficit) {
		super(msg);
		this.deficit = deficit;
	}

	public double getDeficit() {
		return deficit;
	}
}
