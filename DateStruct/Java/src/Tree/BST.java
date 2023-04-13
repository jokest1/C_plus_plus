package Tree;

public class BST <E> extends AbstractTree<E>{
    /**
     * 添加元素分为了添加根节点和添加非根结点
     * 添加根节点直接将结点添加在root上
     * 添加非根结点就需要一直寻找到合适的位置，使用一个parent
     * 记录下父亲结点，根据最后一次cmp的值判断是左子还是右子
     * 假如在比较途中发现cmp是0就只需要将元素覆盖上去直接return
     */
    @Override
    public void add(E element) {
        Base_Node<E> node = this.root;
        if (node==null){
            root=createNode(element,null);
            this.size++;
        }else {
            Base_Node<E> parent=node;
            int cmp = 0;
            while (node!=null){
                parent=node;
                cmp= Compare(element,node.element);
                if (cmp<0){
                    node=node.left;
                }else if (cmp>0){
                    node=node.right;
                }else {
                    node.element=element;
                    return;
                }
            }
            if (cmp<0){
                parent.left=createNode(element,parent);
            }else {
                parent.right=createNode(element,parent);
            }
            this.size++;
        }
    }

    @Override
    public void remove(E element) {

    }

    @Override
    public boolean contains(E element) {
        return false;
    }
}
