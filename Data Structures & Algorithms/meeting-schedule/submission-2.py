"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals = sorted(intervals, key=lambda i:i.start)
        for i in range(1,len(intervals)):
            l1 = intervals[i-1]
            l2 = intervals[i]
            if l1.end > l2.start:
                return False
            
        return True