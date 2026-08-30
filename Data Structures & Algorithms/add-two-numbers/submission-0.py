# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        def add_heads(prev_val, head1, head2):

            if not head1 and not head2:
                if prev_val:
                    return ListNode(prev_val)
                return None

            if not head1:
                new_val = head2.val + prev_val
                if new_val > 9:
                    head2.val = new_val % 10
                    head2.next = add_heads(1, None, head2.next)
                else:
                    head2.val = new_val
                return head2

            if not head2:
                new_val = head1.val + prev_val
                if new_val > 9:
                    head1.val = new_val % 10
                    head1.next = add_heads(1, head1.next, None)
                else:
                    head1.val = new_val
                return head1

            new_val = head1.val + head2.val + prev_val

            if new_val > 9:
                head1.val = new_val % 10
                head1.next = add_heads(1, head1.next, head2.next)
            else:
                head1.val = new_val
                head1.next = add_heads(0, head1.next, head2.next)

            return head1

        return add_heads(0,l1,l2)