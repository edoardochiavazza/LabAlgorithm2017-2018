import java.util.*;

class NotOrientedGraph<T> extends Graph<T> {

  /**
   * Method constructs the struct of empty not oriented Graph
   *
   */
  public NotOrientedGraph() {
    super();
  } // construct

  /**
   * Method constructs the struct of not oriented Graph with a Set of edge
   *
   * @param edgeSet
   */
  public NotOrientedGraph(Set<Edge<T>> edgeSet) {
    super(edgeSet);
  } // construct

  /**
   * Method returns if is a direct graph
   *
   * @return
   */
  @Override
  public boolean isDirect() {
    return false;
  } // isDirect

  /**
   * Method returns the number of the Edges
   *
   * @return
   */
  @Override
  public int getEdgeSize() {
    return super.getEdgeSize() / 2;
  } // getEdgeSize

  /**
   * Methods returns true if can adds Edge, passing a value of src, value of dest
   * and the weight
   *
   * @param edge
   * @return
   */
  @Override
  public boolean addEdge(Edge<T> edge) {
    if(edge == null) return false;
    return super.addEdge(edge.getSource(), edge.getDestination(), edge.getWeight())
        && super.addEdge(edge.getDestination(), edge.getSource(), edge.getWeight());
  } // addEdge

  /**
   * Methods returns true if can adds Edge, passing a value of src, value of dest
   * and the weight
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  @Override
  public boolean addEdge(T source, T destination, int weight) {
    return super.addEdge(new Node<>(source), new Node<>(destination), weight)
        && super.addEdge(new Node<>(destination), new Node<>(source), weight);
  } // addEdge

  /**
   * Methods returns true if can adds Edge, passing Node src, Node dest and the
   * weight
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  @Override
  public boolean addEdge(Node<T> source, Node<T> destination, int weight) {
    return super.addEdge(source, destination, weight) && super.addEdge(destination, source, weight);
  } // addEdge

  /**
   * Methods returns true if can adds Edge, passing a value of src, value of dest
   * and the weight
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  @Override
  public boolean addEdge(T source, T destination, double weight) {
    return super.addEdge(new Node<>(source), new Node<>(destination), weight)
        && super.addEdge(new Node<>(destination), new Node<>(source), weight);
  } // addEdge

  /**
   * Methods returns true if can adds Edge, passing Node src, Node dest and the
   * weight
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  @Override
  public boolean addEdge(Node<T> source, Node<T> destination, double weight) {
    return super.addEdge(source, destination, weight) && super.addEdge(destination, source, weight);
  } // addEdge

  /**
   * Method returns true if can removes Edge, passing value of src, value of dest
   *
   * @param edge
   * @return
   */
  @Override
  public boolean removeEdge(Edge<T> edge) {
    if(edge == null) return false;
    return super.removeEdge(edge.getSource(), edge.getDestination())
        && super.removeEdge(edge.getDestination(), edge.getSource());
  } // removeEdge

  // /**
  //  * Method returns true if can removes Edge, passing value of src, value of dest
  //  *
  //  * @param source
  //  * @param destination
  //  * @return
  //  */
  // @Override
  // public boolean removeEdge(T source, T destination) {
  //   return super.removeEdge(new Node<>(source), new Node<>(destination))
  //       && super.removeEdge(new Node<>(destination), new Node<>(source));
  // } // removeEdge

  /**
   * Methods returns true if can removes Edge, passing Node src, Node dest
   *
   * @param source
   * @param destination
   * @return
   */
  @Override
  public boolean removeEdge(Node<T> source, Node<T> destination) {
    return super.removeEdge(source, destination) && super.removeEdge(destination, source);
  } // removeEdge

} // class
