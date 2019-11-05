import java.util.*;
import static org.junit.Assert.*;
import org.junit.*;

public class TestJUnit {
  UnionFind<Integer> uFind;
  Set<Integer> set;

  @Before
  public void initializeClass() {
    uFind = new UnionFind<>();
    set = new HashSet<>();

    set.add(232);
    set.add(72);
    set.add(2);
    set.add(5);
    set.add(3);
    set.add(4);
    set.add(5);
    set.add(88);
    set.add(3);
    set.add(35);
  }

  @Test
  public void MakeSet() {
    assertTrue(uFind.makeSet(set));
  }

  @Test
  public void EmptyMakeSet() {
    assertFalse(uFind.makeSet(null));
  }

  @Test
  public void Union() {
    uFind.makeSet(set);
    assertTrue(uFind.union(232, 72));
  }

  @Test
  public void NullUnion() {
    uFind.makeSet(set);
    assertFalse(uFind.union(null, null));
  }

  @Test
  public void NotInListUnion() {
    uFind.makeSet(set);
    assertFalse(uFind.union(0, 1));
  }

  @Test
  public void DuplicateUnion() {
    uFind.makeSet(set);
    uFind.union(232, 72);
    assertFalse(uFind.union(232, 72));
  }

  @Test
  public void Find() {
    uFind.makeSet(set);
    uFind.union(232, 72);
    uFind.union(88, 232);

    assertEquals((Integer) 72, uFind.find(88));
  }

  @Test
  public void NullFind() {
    uFind.makeSet(set);
    assertNull(uFind.find(null));
  }

  @Test
  public void NotInListFind() {
    uFind.makeSet(set);
    assertNull(uFind.find(1));
  }

}
