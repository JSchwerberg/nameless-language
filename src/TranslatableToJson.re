let f = (translatable: Translatable.t): Js.Json.t =>
  Json.Encode.(
    object_([
      ("sourceLanguage", string(translatable.sourceLanguage)),
      (
        "translations",
        StringMapToJson.f(translatable.translations, VettableToJson.f),
      ),
    ])
  );
