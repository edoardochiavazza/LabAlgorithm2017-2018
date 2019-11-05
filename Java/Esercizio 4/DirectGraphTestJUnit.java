import java.util.*;
import static org.junit.Assert.*;
import org.junit.*;

public class DirectGraphTestJUnit {
  Graph<Character> grafo;
  Kruskal<Character> kruskal;

  @Before
  public void initializeClass() {
    grafo = new DirectGraph<>();

    grafo.addNode('a');
    grafo.addNode('b');
    grafo.addNode('c');
    grafo.addNode('d');
    grafo.addNode('e');
    grafo.addNode('f');
    grafo.addNode('g');
    grafo.addNode('h');
    grafo.addNode('i');
    grafo.addNode('j');

    grafo.addEdge('a', 'b', 5.0);
    grafo.addEdge('a', 'e', 1.0);
    grafo.addEdge('a', 'd', 4.0);
    grafo.addEdge('b', 'c', 4.0);
    grafo.addEdge('b', 'd', 2.0);
    grafo.addEdge('c', 'j', 2.0);
    grafo.addEdge('c', 'i', 1.0);
    grafo.addEdge('c', 'h', 4.0);
    grafo.addEdge('i', 'j', 0.0);
    grafo.addEdge('g', 'i', 4.0);
    grafo.addEdge('f', 'g', 7.0);
    grafo.addEdge('e', 'f', 1.0);
    grafo.addEdge('d', 'e', 2.0);
    grafo.addEdge('d', 'f', 5.0);
    grafo.addEdge('d', 'g', 11.0);
    grafo.addEdge('d', 'h', 2.0);
    grafo.addEdge('g', 'h', 1.0);
    grafo.addEdge('h', 'i', 6.0);
  }

  @Test
  public void IsDirect() {
    assertTrue(grafo.isDirect());
  }

  @Test
  public void DuplicateNode() {
    assertFalse(grafo.addNode('g'));
  }

  @Test
  public void AddNullNode() {
    assertFalse(grafo.addNode((Character) null));
  }

  @Test
  public void DuplicateEdge() {
    assertFalse(grafo.addEdge('g', 'i', 4.0));
  }

  @Test
  public void AddNullEdge() {
    assertFalse(grafo.addEdge(null));
  }

  @Test
  public void RemoveNode() {
    assertTrue(grafo.removeNode('c'));
  }

  @Test
  public void RemoveNullNode() {
    assertFalse(grafo.removeNode((Character) null));
  }

  @Test
  public void RemoveNotInListNode() {
    assertFalse(grafo.removeNode('x'));
  }

  @Test
  public void RemoveEdge() {
    assertTrue(grafo.removeEdge('f', 'g'));
  }

  @Test
  public void RemoveNullEdge() {
    assertFalse(grafo.removeEdge((Character) null, (Character) null));
  }

  @Test
  public void RemoveNotInListEdge() {
    assertFalse(grafo.removeEdge('x', 'y'));
  }

  @Test
  public void Kruskal() {
    kruskal = new Kruskal<>(grafo.getNodes(), grafo.getEdges());
    kruskal.calcResults();

    assertEquals(14.0, kruskal.getResultWeight(), 0.0);
  }

}
