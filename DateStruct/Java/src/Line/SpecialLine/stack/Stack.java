package Line.SpecialLine.stack;

public interface Stack<E> {
    int size();
    boolean isEmpty();
    void clear();

    void push(E element);
    E pop();
    E peek();
}
