package Line;

public interface LineList<E> {
    static final int ELEMENT_NOT_EXIST=-1;
    int size();
    boolean isEmpty();
    void clear();
    void add(E element);
    void add(int index,E element);
    E remove();
    E remove(int index);
    E get(int index);
    void set(int index,E element);
    void set(E element,E newElement);
    int indexOf(E element);
    boolean contains(E element);
}
