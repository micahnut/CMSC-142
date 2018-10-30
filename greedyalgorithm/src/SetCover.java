import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class SetCover{
	public static LinkedHashMap<String, Set<Integer>> sets = new LinkedHashMap<String, Set<Integer>>();
	public static HashSet<Integer> universe = new HashSet<Integer>();
	private static Set<Integer> currentSet;


	public static void main(String[] args){
		read();

		print();

		setCover();

	}

	public static void read(){
		File file = new File("subSets.txt");
		File file2 = new File("universalset.txt");


		int set =1;

		try{
			BufferedReader in = new BufferedReader(new FileReader(file));
			String line;
			while((line = in.readLine())!=null){
				String elements[] = line.split(",");
				Set<Integer> list = new HashSet<Integer>();
				for(String e : elements){
					list.add(Integer.parseInt(e));

				}
				sets.put("S" + set, list);
				set++;

			}
			in.close();

		}catch (IOException e) {
			System.out.println(e.getMessage());
			System.exit(1);
		}
	


	try{
			BufferedReader r = new BufferedReader(new FileReader(file2));
			String line2;
			while((line2 = r.readLine())!=null){
				String elements[] = line2.split(",");
				for(String e : elements){
					universe.add(Integer.parseInt(e));

				}

			}
			r.close();

		}catch (IOException e) {
			System.out.println(e.getMessage());
			System.exit(1);
		}
	}

	public static void setCover() {
		ArrayList<String> solutionSets = new ArrayList<String>();

		while (!universe.isEmpty()) {
			int best_common_num = 0; //currentSet size
			String bestCurrentSetKey = ""; //currentSet number
			//System.out.println("best_common_num: " + best_common_num);
			//System.out.println("bestCurrentSetKey1: " + bestCurrentSetKey);
			Set<Integer> bestCurrentSet = new HashSet<Integer>();
			
			//System.out.println("sets.keyset: "+ sets.keySet());  //number of sets

			for (String key : sets.keySet()) {
				//System.out.println("key: "+ key);
				currentSet = new HashSet<Integer>(sets.get(key));
				//System.out.println("current1: " + currentSet);
				//System.out.println("universe: " +universe); 
				currentSet.retainAll(universe);
				//System.out.println("current2: " + currentSet);
				//System.out.println("currentsize: " + currentSet.size());
				//System.out.println("best_common_num: " + best_common_num);
				if (best_common_num < currentSet.size()) {
					bestCurrentSetKey = key;
					best_common_num = currentSet.size();
					bestCurrentSet = currentSet;
				}
				//System.out.println("bestCurrentSetKey = "+ bestCurrentSetKey);
				//System.out.println("best_common_num = "+ best_common_num);
				//System.out.println("bestCurrrentSet = "+ bestCurrentSet);
			}
			universe.removeAll(bestCurrentSet);
			solutionSets.add(bestCurrentSetKey);

			//System.out.println("universe: "+ universe);
			//System.out.println("solutionSets: "+ solutionSets);
		}
		System.out.println("Set-cover = " + solutionSets);
	}

	private static void print() {
		for (String key : sets.keySet()) {
			System.out.printf("%-3s = ",key);
			System.out.println(sets.get(key));
		}
		System.out.println("\nUniverse  = " + universe);
	}



}

//f O (M * N *min (M, N)), 
//where N is the number of sets and M is the number of all elements of the union of the N sets. 