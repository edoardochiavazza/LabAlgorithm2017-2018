import java.util.*;

class UnionFind<T> {
  List<T> vertexs = null;
  int edges[] = null;

  /**
   * Return true if the method creates set and set his root to himself
   *
   * @param source Source SET for the class
   * @return
   */
  public boolean makeSet(Set<T> source) {
    if (source == null)
      return false;

    int sourceSize = source.size();
    edges = new int[sourceSize];
    for (int x = 0; x < sourceSize; x++)
      edges[x] = x;
    vertexs = new ArrayList<>(source);
    return true;
  } // makeSet

  /**
   * method returns the index of the value using path compression
   *
   * @param value
   * @return
   */
  public T find(T value){
    if(value == null) return null;

    int vIndex = vertexs.indexOf(value);
    if(vIndex == -1) return null;

    while (vIndex != edges[vIndex]) {
     edges[vIndex] = edges[edges[vIndex]]; // Path compression
     vIndex = edges[vIndex];
    }

    return vertexs.get(vIndex);
  } // find

  /**
   * Method returns true if can union two set. The index of value src become the index of
   * value destination
   *
   * @param src
   * @param dest
   */
  public boolean union(T src, T dest){
    if(src == null) return false;
    if(dest == null) return false;

    int srcIndex  = vertexs.indexOf(find(src));
    int destIndex = vertexs.indexOf(find(dest));

    if(srcIndex  == -1) return false;
    if(destIndex == -1) return false;
    if(srcIndex == destIndex) return false;

    edges[srcIndex] = destIndex;
    return true;
  } // union

  /**
   * Method prints the struct of union-set
   */
  public void printSet() {
    int vertexSize = vertexs.size();
    for (int x = 0; x < vertexSize; x++) {
      System.out.println(vertexs.get(x).toString() + " ---> " + vertexs.get(edges[x]).toString());
    }
  } // printSet
} // class
