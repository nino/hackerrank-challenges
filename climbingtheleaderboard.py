# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

import sys
import unittest


def get_unique_scores(scores):
    ret = [scores[0]]
    for score in scores:
        if score != ret[-1]:
            ret.append(score)
    return ret


def get_rank(alice, scores):
    rank = 1
    for score in scores:
        if alice >= score:
            return rank
        else:
            rank += 1
    return rank


def climbing_leaderboard(scores, alice_scores):
    unique_scores = get_unique_scores(scores)
    ret = []
    alice_rank = len(unique_scores) + 1
    for alice_score in alice_scores:
        while alice_rank > 1 and alice_score >= unique_scores[alice_rank - 2]:
            alice_rank -= 1
        ret.append(alice_rank)
    return ret


class TestLeaderboard(unittest.TestCase):
    def test_climbing_leaderboard(self):
        scores = [100, 100, 50, 40, 40, 20, 10]
        alice_scores = [5, 25, 50, 120]
        expected = [6, 4, 2, 1]
        actual = climbing_leaderboard(scores, alice_scores)
        self.assertEqual(actual, expected)


if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == 'test':
        unittest.main()
    else:
        scores_count = int(input())
        scores = list(map(int, input().rstrip().split()))
        alice_count = int(input())
        alice = list(map(int, input().rstrip().split()))
        result = climbing_leaderboard(scores, alice)
        print('\n'.join(map(str, result)))
        print('\n')
