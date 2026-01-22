let shareCount = $state(0);

export function getShareCount() {
    return shareCount;
}

export function incrementShareCount() {
    shareCount += 1;
}

export function resetShareCount() {
    shareCount = 0;
}
