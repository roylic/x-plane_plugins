"""
Significantly edited down version of pyperclip, by Al Sweigart al@inventwithpython.com
His module is much more flexible and robust (and includes copything to the Clipboard).

As I didn't need all that, I simplified to bare minimum.

BSD License
"""
import platform
import subprocess
import time
import contextlib

import ctypes
from ctypes import c_wchar_p
from ctypes.wintypes import (HWND, BOOL, HANDLE, UINT)


def darwin_paste():
    p = subprocess.run(['pbpaste', 'r'], capture_output=True)
    return p.stdout.decode('utf-8').split('\n')


def win_paste():
    @contextlib.contextmanager
    def clipboard(hwnd):
        t = time.time() + 0.5
        success = False
        OpenClipboard = ctypes.windll.user32.OpenClipboard
        OpenClipboard.argtypes = [HWND]
        OpenClipboard.restype = BOOL
        CloseClipboard = ctypes.windll.user32.CloseClipboard
        CloseClipboard.argtypes = []
        CloseClipboard.restype = BOOL

        while time.time() < t:
            success = OpenClipboard(hwnd)
            if success:
                break
            time.sleep(0.01)
        # if not success:
        #     print("not successful")
        # else:
        #     print("Success opening clipboard")
        try:
            yield
        finally:
            CloseClipboard()

    CF_UNICODE_TEXT = 13
    GetClipboardData = ctypes.windll.user32.GetClipboardData
    GetClipboardData.argtypes = [UINT]
    GetClipboardData.restype = HANDLE

    with clipboard(None):
        handle = GetClipboardData(CF_UNICODE_TEXT)
        if not handle:
            return ""
        res = c_wchar_p(handle).value
        return res.split('\r\n')

    
def lin_paste():
    try:
        p = subprocess.run(['xclip', '-o'], capture_output=True)
    except Exception as e:
        print("Failed to run xclip successfully")
        return ""
    return p.stdout.decode('utf-8').split('\n')


def getClipboard():
    if platform.system() == 'Darwin':
        return darwin_paste()
    elif platform.system() == 'Windows':
        return win_paste()
    elif platform.system() == 'Linux':
        return lin_paste()

    print("paste not supported on this platform")
    return ""


if __name__ == '__main__':
    res = getClipboard()
    print(f"Got {len(res)} lines, {res}")
