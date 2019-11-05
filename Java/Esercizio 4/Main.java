import java.util.*;
import java.io.*;

class Main {

  /**
   * Main reads the file and excutes the Kruskal's class
   *
   * @param args
   */
  public static void main(String[] args) {
    if (args.length < 1) {
      System.out.println("Inserire il nome del data-file come argomento.");
      System.exit(1);
    }

    Set<Edge<String>> dataEdges = readData(args[0]);
    if (dataEdges == null) {
      System.out.println("Il data-file non è stato trovato.");
      System.exit(1);
    }

    Graph<String> grafo = new DirectGraph<>(dataEdges);
    System.out.println("Il data-file contiene " + grafo.getNodeSize() + " nodi e " + grafo.getEdgeSize() + " archi.");

    Kruskal<String> krus = new Kruskal<>(grafo);
    System.out.println("Calcolo...");
    krus.calcResults();

    System.out.print("Cammino minimo del grafo: " + Math.round(krus.getResultWeight()) + "\n");
  } // main

  /**
   * Function which reads the file and construct the edges for Kruskal
   *
   * @param fileName
   * @return
   */
  public static Set<Edge<String>> readData(String fileName) {
    Set<Edge<String>> toReturn = null;

    File f = new File(fileName);
    try (BufferedReader br = new BufferedReader(new FileReader(f))) {
      toReturn = new HashSet<>();
      String line;
      while ((line = br.readLine()) != null) {
        String params[] = line.split(",");
        Edge<String> edgeToAdd = new Edge<>(params[0], params[1], Double.parseDouble(params[2]));
        toReturn.add(edgeToAdd);
      }
    } catch (Exception e) {
    }
    return toReturn;
  } // readData

} // class
