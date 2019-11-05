import java.util.*;

class Kruskal<T> {
  private Set<Node<T>> nodes;
  private Set<Edge<T>> edges;

  private UnionFind<Node<T>> unionFind;
  private Set<Edge<T>> resultEdges;
  private double resultWeight;

  /**
   * Method constructs Kruskal struct, passing only the Graph
   *
   *
   * @param g
   */
  public Kruskal(Graph<T> g) {
    this(g.getNodes(), g.getEdges());
  } // construct

  /**
   * Method constructs Kruskal struct, passing all node of the Set and all Edges
   * of the Set
   *
   * @param n
   * @param e
   */
  public Kruskal(Set<Node<T>> n, Set<Edge<T>> e) {
    this.nodes = n;
    this.edges = e;
    this.resultEdges = new HashSet<>();
    this.unionFind = new UnionFind<>();
    this.resultWeight = 0.0;

    unionFind.makeSet(this.nodes);
  } // construct

  /**
   * Method calcolates the minimum path to connect the nodes and return it such
   * integer
   *
   */
  public void calcResults() {
    for (Edge<T> ed : edges) {
      if (unionFind.find(ed.getSource()) != unionFind.find(ed.getDestination())) {
        resultEdges.add(ed);
        resultWeight += ed.getWeight();
        unionFind.union(ed.getSource(), ed.getDestination());
      }
    }
  } // calcResults

  /**
   * Method return the resultant Edges
   *
   * @return
   */
  public Set<Edge<T>> getResultEdges() {
    return this.resultEdges;
  } // getResultEdges

  /**
   * Method return the resultant Edges
   *
   * @return
   */
  public double getResultWeight() {
    return this.resultWeight;
  } // getResultWeight

}
