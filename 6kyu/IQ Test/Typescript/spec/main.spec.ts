function requireAll(requireContext: __WebpackModuleApi.RequireContext): void {
    requireContext.keys().map(requireContext);
}

requireAll(require.context(".", true, /[sS]pec\.ts$/));
