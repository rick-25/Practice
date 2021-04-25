import java.io.*;
import java.util.*;


public class SortFile {
    public static void main(String[] args) throws IOException {

        String inputFile = "input.txt";
        String outputFile = "output.txt";

        ArrayList<String> list = new ArrayList<String>();
        Map<String, String> map = new HashMap<String, String>();    



        getInput(list, map, inputFile);
        writeData(list, map, outputFile);
    }

    private static void getInput(ArrayList<String> list, Map<String, String> map, String file) throws IOException {

        Scanner sc = new Scanner(new File(file));

        while(true) {
            String ques, ans;
            ques = ans = "";

            while(sc.hasNextLine() && ques.length() == 0) ques = sc.nextLine();
            while(sc.hasNextLine() && ans.length() == 0) ans = sc.nextLine();

            if(ques.length() == 0) break;

            list.add(ques);
            map.put(ques, ans);
        }

        sc.close();


        Collections.sort(list);

    }
    
    private static void writeData(ArrayList<String> list, Map<String, String> map, String file) throws IOException {

        FileWriter fw = new FileWriter(new File(file)); 
        fw.write('\n');
        fw.close();


        fw = new FileWriter(new File(file), true);
        for(int i=0; i<list.size(); i++) 
            fw.write("Q: " + list.get(i) + "\n" + "A: " + map.get(list.get(i)) + "\n\n");
        fw.close();
    }

}
