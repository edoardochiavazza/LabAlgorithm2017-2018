import java.util.*;

class DirectGraph<T> extends Graph<T> {

  /**
   * Method constructs the struct of empty and direct Graph
   *
   */
  public DirectGraph() {
    super();
  } // construct

  /**
   * Method constructs the struct of and direct Graph, passing a Set of edge
   *
   * @param edgeSet
   */
  public DirectGraph(Set<Edge<T>> edgeSet) {
    super(edgeSet);
  } // construct

  /**
   * Method return true if is direct graph
   *
   * @return
   */
  @Override
  public boolean isDirect() {
    return true;
  } // isDirect

} // class
