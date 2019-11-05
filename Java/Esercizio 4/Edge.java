import java.util.Objects;

class Edge<T> implements Comparable<Edge<T>> {
  private final double weight;
  private final Node<T> source;
  private final Node<T> destination;

  /**
   * Method construct edge between src and Node dest with weight
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(T source, T destination, int weight) {
    this(new Node<>(source), new Node<>(destination), weight);
  } // construct

  /**
   * Method construct edge between Node src and Node dest with weight
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(Node<T> source, Node<T> destination, int weight) {
    this.source = source;
    this.destination = destination;
    this.weight = weight;
  } // construct

  /**
   * Method construct edge between src and Node dest with weight
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(T source, T destination, double weight) {
    this(new Node<>(source), new Node<>(destination), weight);
  } // construct

  /**
   * Method construct edge between Node src and Node dest with weight
   *
   * @param source
   * @param destination
   * @param weight
   */
  public Edge(Node<T> source, Node<T> destination, double weight) {
    this.source = source;
    this.destination = destination;
    this.weight = weight;
  } // construct

  /**
   * Method return node src
   *
   * @return
   */
  public Node<T> getSource() {
    return this.source;
  } // getSource

  /**
   * Method return node dest
   *
   * @return
   */
  public Node<T> getDestination() {
    return this.destination;
  } // getDestination

  /**
   * Method return weight of an edge
   *
   * @return
   */
  public double getWeight() {
    return this.weight;
  } // getWeight

  /**
   * Method controls if the two obj are the same. Return true if they are the same
   * obj
   *
   * @param toCheck
   * @return
   */
  @Override
  public boolean equals(Object toCheck) {
    if (toCheck == null)
      return false;
    if (toCheck == this)
      return true;
    if (!(toCheck instanceof Edge<?>))
      return false;

    Edge<T> edgeToCheck = (Edge<T>) toCheck;
    return Objects.equals(this.source, edgeToCheck.source) && Objects.equals(this.destination, edgeToCheck.destination);
  } // equals

  /**
   * Method calcolates the hash code for the edge
   *
   * @return
   */
  @Override
  public int hashCode() {
    return source.hashCode() + (31 * destination.hashCode());
  } // hashCode

  /**
   * Method returns String of src to dest
   *
   * @return
   */
  @Override
  public String toString() {
    return "Edge{Source: " + this.source.toString() + ", Destination: " + this.destination.toString() + ", Weight: "
        + this.weight + "}";
  } // toString

  /**
   * Method compares the twho edge and sort them in increasing mode
   *
   * @return
   */
  @Override
  public int compareTo(Edge<T> e) {
    if (this.weight <= e.weight) {
      return -1;
    }
    return 1;
  } // compareTo

} // class
