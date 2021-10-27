
public abstract class PrintableObject implements Shape, Printable {
	@Override
	public String toString() {
		return this.getName();
	}

	@Override
	public void print() {
		System.out.println(toString());
	}
	
}
