public interface NamedObject {
	default public String getName() {
		String className = this.getClass().getSimpleName();
		return className;
	}
}
