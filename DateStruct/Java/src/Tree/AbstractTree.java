package Tree;
import Tree.printer.BinaryTreeInfo;

import java.util.Comparator;

public abstract class AbstractTree <E> implements Tree<E>,BinaryTreeInfo {
    @Override
    public Object root() {
        return this.root;
    }

    @Override
    public Object left(Object node) {
        return ((Base_Node<E>)node).left;
    }

    @Override
    public Object right(Object node) {
        return ((Base_Node<E>)node).right;
    }

    @Override
    public Object string(Object node) {
        return ((Base_Node<E>)node).element.toString();
    }

    /**
     * 设计结点结点一定有父节点但不一定有子节点
     */
    protected static class Base_Node<E>{
        E element;
        Base_Node<E>left;
        Base_Node<E>right;
        Base_Node<E>parent;

        public Base_Node(E element, Base_Node<E> parent) {
            this.element = element;
            this.parent = parent;
        }
    }

    /**
     * 一个根节点root，记录所有元素总数size，可以自定义比较方法的compare
     * 对compare的两种构造方法：无参构造、带参构造
     */
    protected Base_Node<E> root;
    protected int size;
    protected Comparator<E> compare;

    public AbstractTree() {
        this(null);
    }

    public AbstractTree(Comparator<E> compare) {
        this.compare = compare;
    }

    /**
     *将比较方法和对结点的构造进行工具方法设计，方便之后的扩展类重写
     */
    protected int Compare(E e1,E e2){
        if (compare==null){
            return ((Comparable)e1).compareTo(e2);
        }else{
            return compare.compare(e1,e2);
        }
    }
    protected Base_Node<E> createNode(E element,Base_Node<E> parent){
        return new Base_Node<>(element,parent);
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean isEmpty() {
        return this.size==0;
    }

    @Override
    public void clear() {
        size=0;
        root=null;
    }

    @Override
    public abstract void add(E element);

    @Override
    public abstract void remove(E element);

    @Override
    public abstract boolean contains(E element);
}
