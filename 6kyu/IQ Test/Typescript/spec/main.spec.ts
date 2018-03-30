const requireAll = (requireContext: __WebpackModuleApi.RequireContext) => {
    requireContext.keys()
        .map(requireContext);
};

requireAll(require.context(".", true, /[sS]pec\.ts$/));
