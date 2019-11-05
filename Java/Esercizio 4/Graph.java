import java.util.*;

abstract class Graph<T> {
  protected Map<Node<T>, Map<Node<T>, Double>> nodes;
  // Cache Variables
  private int cacheNodeSize;
  private int cacheEdgeSize;
  private Set<Edge<T>> cacheEdgeSet;

  /**
   * Method constructs the struct of empty Graph
   *
   */
  public Graph() {
    this.nodes = new HashMap<>();
    this.cacheNodeSize = -1;
    this.cacheEdgeSize = -1;
    this.cacheEdgeSet = null;
  } // construct

  /**
   * Method constructs the struct of Graph with a Set of edge
   *
   * @param edgeSet
   */
  public Graph(Set<Edge<T>> edgeSet) {
    this();
    if (edgeSet == null)
      return;

    for (Edge<T> e : edgeSet) {
      Node<T> source = e.getSource();
      Node<T> destination = e.getDestination();
      this.addNode(source);
      this.addNode(destination);
      this.addEdge(source, destination, e.getWeight());
    }
  } // construct

  public boolean isDirect(){
    return true;
  }

  /**
   * Return the SET of the nodes
   *
   * @return
   */
  public Set<Node<T>> getNodes() {
    if (nodes.size() == 0)
      return null;
    return nodes.keySet();
  } // getNodes

  /**
   * Method returns the SET of Edges
   *
   * @return
   */
  public Set<Edge<T>> getEdges() {
    if (nodes.size() == 0)
      return null;
    if (this.cacheEdgeSet != null)
      return this.cacheEdgeSet;

    this.cacheEdgeSet = new TreeSet<>();
    for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
      for (Map.Entry<Node<T>, Double> edge : node.getValue().entrySet()) {
        this.cacheEdgeSet.add(new Edge<>(node.getKey(), edge.getKey(), edge.getValue()));
      }
    }
    return this.cacheEdgeSet;
  } // getEdges

  /**
   * Method returns the number of the nodes
   *
   * @return
   */
  public int getNodeSize() {
    if (this.cacheNodeSize > -1)
      return this.cacheNodeSize;
    return this.cacheNodeSize = nodes.size();
  } // getNodeSize

  /**
   * Method returns the number of the Edges
   *
   * @return
   */
  public int getEdgeSize() {
    if (this.cacheEdgeSize > -1)
      return this.cacheEdgeSize;
    this.cacheEdgeSize = 0;
    for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
      this.cacheEdgeSize += node.getValue().size();
    }
    return this.cacheEdgeSize;
  } // getEdgeSize

  /**
   * Method returns the HasMap of adj nodes, passing a value
   *
   * @param value
   * @return
   */
  public Set<Node<T>> getAdjentNodes(T value) {
    return this.getAdjentNodes(new Node<>(value));
  } // getAdjentNodes

  /**
   * Method returns the HasMap of adj nodes, passing a Nodes
   *
   * @param value
   * @return
   */
  public Set<Node<T>> getAdjentNodes(Node<T> value) {
    if (nodes.size() == 0)
      return null;

    Set<Node<T>> adjentNodes = new HashSet<>();
    Map<Node<T>, Double> sourceNode = nodes.get(value);
    if (sourceNode == null)
      return null;

    for (Map.Entry<Node<T>, Double> edge : sourceNode.entrySet())
      adjentNodes.add(edge.getKey());
    return adjentNodes;
  } // getAdjentNodes

  /**
   * Method returns the weight of edges(src to destination), passing twho values
   *
   * @param source
   * @param destination
   * @return
   */
  public double getEdgeWeight(T source, T destination) {
    return this.getEdgeWeight(new Node<>(source), new Node<>(destination));
  } // getEdgeWeight

  /**
   * Method returns the HasMap of adj nodes, passing a value
   *
   * @param source
   * @param destination
   * @return
   */
  public double getEdgeWeight(Node<T> source, Node<T> destination) {
    if (nodes.containsKey(source)) {
      Map<Node<T>, Double> edges = nodes.get(source);
      if (edges.containsKey(destination)) {
        return edges.get(destination);
      }
    }
    return -1.0;
  } // getEdgeWeight

  /**
   * Method adds node to the Graph
   *
   * @param value
   * @return
   */
  public boolean addNode(T value) {
    return this.addNode(new Node<>(value));
  } // addNode

  /**
   * Method adds node to the Graph. Return true in case of success
   *
   * @param value
   * @return
   */
  public boolean addNode(Node<T> value) {
    if(value == null || value.getValue() == null) return false;
    this.cacheNodeSize = -1;
    return nodes.putIfAbsent(value, new HashMap<>()) == null;
  } // addNode

  /**
   * Method adds edges to the Graph, passing value of src value dest and the
   * weight. Return true in case of success
   *
   * @param edge
   * @return
   */
  public boolean addEdge(Edge<T> edge) {
    if(edge == null) return false;
    return this.addEdge(edge.getSource(), edge.getDestination(), edge.getWeight());
  } // addEdge

  /**
   * Method adds edges to the Graph, passing value of src value dest and the
   * weight. Return true in case of success
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  public boolean addEdge(T source, T destination, int weight) {
    return this.addEdge(new Node<>(source), new Node<>(destination), weight);
  } // addEdge

  /**
   * Method adds edges to the Graph, passing value of src value dest and the
   * weight. Return true in case of success
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  public boolean addEdge(Node<T> source, Node<T> destination, int weight) {
    return this.addEdge(source, destination, weight);
  } // addEdge

  /**
   * Method adds edges to the Graph, passing value of src value dest and the
   * weight. Return true in case of success
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  public boolean addEdge(T source, T destination, double weight) {
    return this.addEdge(new Node<>(source), new Node<>(destination), weight);
  } // addEdge

  /**
   * Method adds edges to the Graph, passing Node src Node dest and the weight.
   * Return true in case of success
   *
   * @param source
   * @param destination
   * @param weight
   * @return
   */
  public boolean addEdge(Node<T> source, Node<T> destination, double weight) {
    if(source == null || source.getValue() == null) return false;
    if(destination == null || destination.getValue() == null) return false;

    this.cacheEdgeSize = -1;
    this.cacheEdgeSet = null;

    if (nodes.containsKey(source) && nodes.containsKey(destination)) {
      return nodes.get(source).putIfAbsent(destination, weight) == null;
    }
    return false;
  } // addEdge

  /**
   * Method returns true if a value is conteined in the HashMap, passing a value
   *
   * @param value
   * @return
   */
  public boolean containsNode(T value) {
    return nodes.containsKey(new Node<>(value));
  } // containsNode

  /**
   * Method returns true if a value is conteined in the HashMap, passing a Node
   *
   * @param value
   * @return
   */
  public boolean containsNode(Node<T> value) {
    return nodes.containsKey(value);
  } // containsNode

  /**
   * Method returns true if a edge is conteined in the HashMap, passing the value
   * of src and the value of dest
   *
   * @param source
   * @param destination
   * @return
   */
  public boolean containsEdge(T source, T destination) {
    return this.containsEdge(new Node<>(source), new Node<>(destination));
  } // containsEdge

  /**
   * Method returns true if a edge is conteined in the HashMap, passing the src
   * Node and dest Node
   *
   * @param source
   * @param destination
   * @return
   */
  public boolean containsEdge(Node<T> source, Node<T> destination) {
    if (nodes.containsKey(source) && nodes.containsKey(destination)) {
      return nodes.get(source).containsKey(destination);
    }
    return false;
  } // containsEdge

  /**
   * Methods returns true if can removes Node, passing a value
   *
   * @param value
   * @return
   */
  public boolean removeNode(T value) {
    return this.removeNode(new Node<>(value));
  } // removeNode

  /**
   * Methods returns true if can removes Node, passing a Node
   *
   * @param value
   * @return
   */
  public boolean removeNode(Node<T> value) {
    if(value == null || value.getValue() == null) return false;
    this.cacheNodeSize = -1;

    for (Map.Entry<Node<T>, Map<Node<T>, Double>> node : nodes.entrySet()) {
      if (node.getKey().equals(value))
        continue;
      node.getValue().remove(value);
    }
    return nodes.remove(value) != null;
  } // removeNode

  /**
   * Methods returns true if can removes Edge, passing src value, dest value
   *
   * @param edge
   * @return
   */
  public boolean removeEdge(Edge<T> edge) {
    if(edge == null) return false;
    return this.removeEdge(edge.getSource(), edge.getDestination());
  } // removeNode

  /**
   * Methods returns true if can removes Edge, passing src value, dest value
   *
   * @param source
   * @param destination
   * @return
   */
  public boolean removeEdge(T source, T destination) {
    return this.removeEdge(new Node<>(source), new Node<>(destination));
  } // removeNode

  /**
   * Methods returns true if can removes Edge, passing Node src,Node dest
   *
   * @param source
   * @param destination
   * @return
   */
  public boolean removeEdge(Node<T> source, Node<T> destination) {
    if(source == null || source.getValue() == null) return false;
    if(destination == null || destination.getValue() == null) return false;

    this.cacheEdgeSize = -1;
    this.cacheEdgeSet = null;

    if (nodes.containsKey(source)) return nodes.get(source).remove(destination) != null;
    return false;
  } // removeNode

} // class
