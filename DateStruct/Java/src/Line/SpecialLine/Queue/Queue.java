package Line.SpecialLine.Queue;

public interface Queue <E>{
    int size();
    void clear();
    boolean isEmpty();
    void push_back(E element);
    void push_head(E element);
    E peek_head();
    E peek_back();
    E pop_head();
    E pop_back();
    void insert(int index,E element);
}
