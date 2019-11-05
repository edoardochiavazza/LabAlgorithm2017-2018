import java.util.Objects;

class Node<T> {
  private T value;

  /**
   * Method constructs Node, passing value
   *
   * @param value
   */
  public Node(T value){
    this.value = value;
  } //construct

  /**
   * Method returns the value of node
   * @return
   */
  public T getValue(){
    return this.value;
  } //getValue

  /**
   * Method controls if the two obj are the same. Return true if they are the same obj
   *
   * @param toCheck
   * @return
   */
  @Override
  @SuppressWarnings("unchecked")
  public boolean equals(Object toCheck){
    if(toCheck == null) return false;
    if(toCheck == this) return true;
    if(!(toCheck instanceof Node<?>)) return false;

    Node<T> nodeToCheck = (Node<T>)toCheck;
    return Objects.equals(value, nodeToCheck.value);
  } //equals

  /**
   * Method calcolates the hash code for the Node
   *
   * @return
   */
  @Override
  public int hashCode(){
    return 31 * value.hashCode();
  } //hashCode

  /**
   *  Method returns String of the value of the node
   *
   * @return
   */
  @Override
  public String toString(){
    return "Node{Value: " + value.toString() + "}";
  } //toString
} //class
