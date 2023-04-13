package Line;
import Line.Array.Array;
import Line.DoubleLinked.CircleDoubleLinkList;
import Line.DoubleLinked.DoubleLinkList;
import Line.Linked.CircleLinkList;
import Line.Linked.LinkList;


/**
 *
 */
public class Main {
    static void testList(LineList<Integer> list) {
        list.add(11);
        list.add(22);
        list.add(33);
        list.add(44);

        list.add(0, 55); // [55, 11, 22, 33, 44]
        list.add(2, 66); // [55, 11, 66, 22, 33, 44]
        list.add(list.size(), 77); // [55, 11, 66, 22, 33, 44, 77]

        list.remove(0); // [11, 66, 22, 33, 44, 77]
        list.remove(2); // [11, 66, 33, 44, 77]
        list.remove(list.size() - 1); // [11, 66, 33, 44]

        Asserts.test(list.indexOf(44) == 3);
        Asserts.test(list.indexOf(22) == LineList.ELEMENT_NOT_EXIST);
        Asserts.test(list.contains(33));
        Asserts.test(list.get(0) == 11);
        Asserts.test(list.get(1) == 66);
        Asserts.test(list.get(list.size() - 1) == 44);

        System.out.println(list);
    }
    public static void main(String[] args) {
        testList(new LinkList<>());
        testList(new Array<>());
        testList(new CircleLinkList<>());
        testList(new DoubleLinkList<>());
        testList(new CircleDoubleLinkList<>());

    }
}
