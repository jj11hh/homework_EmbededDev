#!/usr/bin/env bash

awk -F: '{print $1}' /etc/passwd
