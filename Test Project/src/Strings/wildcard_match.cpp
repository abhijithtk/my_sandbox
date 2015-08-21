public class PatternProduce {

	public static void produce(char[] in, int index, String output) {
		if(index == in.length) {
			System.out.println(" " + output);
			return;
		}
		
		if(in[index] == '?') {
			produce(in, index+1, output+"0");
			produce(in, index+1, output+"1");
		} else {
			produce(in, index+1, output+in[index]);
		}
		
	}
	
	public static void main(String[] args) {
		String in = "10?";
		produce(in.toCharArray(), 0, new String());
		in = "01?0?";
		produce(in.toCharArray(), 0, new String());
	}
	
}
